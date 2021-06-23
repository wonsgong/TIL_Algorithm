import sys
from collections import deque
sys.setrecursionlimit(int(1e9))
read = sys.stdin.readline

def makeTree(curNode, par_) :
    for node in V[curNode] :
        if node != par_ :
            child[curNode].append(node)
            # par[node] = curNode
            makeTree(node, curNode)

def cntSubtree(curNode) :
    size[curNode] = 1
    for node in child[curNode] :
        cntSubtree(node)
        size[curNode] += size[node]

N,R,Q = map(int,read().split())
V = [[] for _ in range(N+1)]
child = [[] for _ in range(N+1)]
size = [0 for _ in range(N+1)]
for _ in range(N-1) :
    x,y = map(int,read().split())
    V[x].append(y)
    V[y].append(x)

makeTree(R, -1)
cntSubtree(R)

for _ in range(Q) :
    q = int(read())
    print(size[q])