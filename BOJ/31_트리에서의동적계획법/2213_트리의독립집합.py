import sys
sys.setrecursionlimit(int(1e9))
read = sys.stdin.readline

def makeTree(curNode, par) :
    for node in adjs[curNode] :
        if node != par :
            makeTree(node, curNode)
    
    dist[curNode][0] = 0
    dist[curNode][1] = weight[curNode-1]
    for node in adjs[curNode] :
        if node != par :
            dist[curNode][0] += max(dist[node][0],dist[node][1])
            dist[curNode][1] += dist[node][0]

def trace(curNode,isInclude,par) :
    if isInclude :
        res.append(curNode)
        for node in adjs[curNode] :
            if node != par :
                trace(node, 0, curNode)
    else :
        for node in adjs[curNode] :
            if node != par :
                if dist[node][0] < dist[node][1] :
                    trace(node,1,curNode)
                else :
                    trace(node,0,curNode)

N = int(read())
weight = list(map(int,read().split()))
adjs = [[] for _ in range(N+1)]
dist = [[0,0] for _ in range(N+1)]
res = []
for _ in range(N-1) :
    x,y = map(int,read().split())
    adjs[x].append(y)
    adjs[y].append(x)

makeTree(1, 0)
print(max(dist[1][0],dist[1][1]))
if dist[1][0] < dist[1][1] :
    trace(1, 1, 0)
else :
    trace(1, 0, 0)

res.sort()
for r in res :
    print(r,end=' ')