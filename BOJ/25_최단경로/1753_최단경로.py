import sys
import heapq

read = sys.stdin.readline

def bfs(st) :
    heap = []
    heapq.heappush(heap, (0,st))
    dist[st] = 0

    while heap :
        cost,cur = heapq.heappop(heap)
        print(cost,cur)
        if dist[cur] < cost : continue

        for nx,nxc in adjmat[cur] :
            nextCost = nxc + cost
            if dist[nx] > nextCost :
                dist[nx] = nextCost
                heapq.heappush(heap, (nextCost,nx))

V,E = map(int,read().split())
K = int(read())
adjmat = [[] for _ in range(V+1)]
INF = sys.maxsize
dist = [INF for _ in range(V+1)]

for _ in range(E) :
    x,y,c = map(int,read().split())
    adjmat[x].append((y,c))

bfs(K)

for i in range(1,V+1) :
    if dist[i] == INF :
        print("INF")
    else :
        print(dist[i])
