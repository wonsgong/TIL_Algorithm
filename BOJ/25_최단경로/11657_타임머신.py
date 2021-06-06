import sys

read = sys.stdin.readline
INF = int(1e9)

def bellman() : 

    dist[1] = 0
    isCycle = False
    for i in range(1,N+1):
        for j in range(M) :
            f = adj[j][0]
            t = adj[j][1]
            c = adj[j][2]

            if dist[f] == INF : continue
            if dist[t] > dist[f] + c :
                if i == N : 
                    isCycle = True
                dist[t] = dist[f] + c  
    return isCycle

N,M = map(int,read().split())
dist = [INF for _ in range(N+1)]
adj = []
for _ in range(M) :
    x,y,c = map(int,read().split())
    adj.append((x,y,c))

if bellman() :
    print(-1)
else :
    for i in range(2,N+1) :
        if dist[i] >= INF : 
            print(-1)
        else :
            print(dist[i])
