import sys
import heapq
# 해당되는 부분으로 쪼개서 최단경로를 구해주면 된다. 
# ans == INF => ans >= INF 로 수정해줌.

read = sys.stdin.readline

def dji(st,ed) :

    dist = [INF for _ in range(N+1)]
    heap = []
    heapq.heappush(heap, (0,st))
    dist[st] = 0

    while heap :
        cost,cur = heapq.heappop(heap)
        if dist[cur] < cost : continue
        for nx,nxc in adjmat[cur] :
            nextCost = cost + nxc
            if dist[nx] > nextCost :
                dist[nx] = nextCost
                heapq.heappush(heap, (nextCost,nx))
    
    return dist[ed]


N,E = map(int,read().split())
adjmat = [[] for _ in range(N+1)]
for _ in range(E) :
    x,y,c = map(int, read().split())
    adjmat[x].append((y,c))
    adjmat[y].append((x,c))
V1,V2 = map(int,read().split())
INF = sys.maxsize



P1 = dji(1,V1) + dji(V1,V2) + dji(V2,N)
P2 = dji(1,V2) + dji(V2,V1) + dji(V1,N)
ans = min(P1,P2)

if ans >= INF :
    print(-1)
else :
    print(ans)

