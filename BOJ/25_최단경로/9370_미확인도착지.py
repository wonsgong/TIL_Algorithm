import sys
import heapq

read = sys.stdin.readline
INF = sys.maxsize

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

T = int(read())
for _ in range(T) :
    N,M,D = map(int,read().split())
    S,G,H = map(int,read().split())

    adjmat = [[] for _ in range(N+1)]
 
    for _ in range(M) :
        x,y,c = map(int, read().split())
        adjmat[x].append((y,c))
        adjmat[y].append((x,c))
    dest = [int(read()) for _ in range(D)]

    ans = []
    for d in dest :
        P1 = dji(S,G) + dji(G,H) + dji(H, d)
        P2 = dji(S,H) + dji(H,G) + dji(G, d)
        if dji(S,d) == min(P1,P2) :
            ans.append(d)
    ans = sorted(ans)
    for a in ans : print(a,end=" ")
    print()