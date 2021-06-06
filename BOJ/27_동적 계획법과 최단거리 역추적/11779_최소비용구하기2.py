import heapq
import sys

read = sys.stdin.readline
INF = int(1e9)

# DSLR 과 동일한 풀이과정

def dji() :
    pq = []
    heapq.heappush(pq,[0,st,str(st)]) # cost , here , path
    dp[st] = 0
    while pq :
        cost,here,path = heapq.heappop(pq)
        if here == ed :
            print(cost)
            print(len(path.split()))
            print(path)
            break
        if dp[here] < cost : continue

        for next_,dist in adjs[here] :
            nextCost = cost + dist

            if dp[next_] > nextCost :
                dp[next_] = nextCost
                heapq.heappush(pq,[nextCost,next_,path+" "+str(next_)])

N = int(read())
M = int(read())
adjs = [[] for _ in range(N+1)]
dp = [INF for _ in range(N+1)]
par = [0 for _ in range(N+1)]
for _ in range(M) :
    x,y,c = map(int,read().split())
    adjs[x].append([y,c])

st,ed = map(int,read().split())
dji()