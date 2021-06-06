import sys
import heapq
read = sys.stdin.readline
INF = int(1e9)
'''
냅색 문제 처럼 풀었는데 최소힙을 사용해서 풀수 있지않을까.ㅜ 
python 시간초과 , pypy 통과
dist 배열에서 아이디어 얻어서 최소힙 사용해서 품 -> 시간초과. 
같은 알고리즘으로 C++ 은 통과
'''
def dji():
    dist = [[INF] * (M+1) for _ in range(N+1)]
    dist[1][0] = 0
    q = []
    heapq.heappush(q, (0, 0, 1))  # time , cost , here

    while q:
        time, cost, here = heapq.heappop(q)

        if dist[here][cost] < time:
            continue

        for nx, nxc, nxt in adjs[here]:
            nextCost = cost + nxc
            nextTime = time + nxt
            if nextCost > M:
                continue

            if dist[nx][nextCost] > nextTime:
                for i in range(nextCost, M+1):
                    if dist[nx][i] > nextTime:
                        dist[nx][i] = nextTime
                heapq.heappush(q, (nextTime, nextCost, nx))

    return dist[N][M]

T = int(read())
for _ in range(T):
    N, M, K = map(int, read().split())
    adjs = [[] for _ in range(N+1)]
    for _ in range(K):
        x, y, c, b = map(int, read().split())
        adjs[x].append((y, c, b))

    dp = [[INF] * (M+1) for _ in range(N+1)]
    dp[1][0] = 0 # vertex , budget , cost

    for budget in range(M+1) :
        for here in range(1,N+1) :
            if dp[here][budget] == INF : continue

            cost = dp[here][budget]
            for nx,nxc,nxb in adjs[here] :
                if nxc + budget > M : continue
                dp[nx][nxc+budget] = min(dp[nx][nxc+budget],cost+nxb)
        
    ans = min(dp[N])

    if ans == INF :
        print("Poor KCM")
    else :
        print(ans)
