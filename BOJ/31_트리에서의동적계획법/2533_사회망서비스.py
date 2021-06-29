import sys

read = sys.stdin.readline
sys.setrecursionlimit(int(1e9))
def dfs(cur) :
    visited[cur] = 1

    dp[cur][0] = 0
    dp[cur][1] = 1

    for nextNode in adjs[cur] :
        if visited[nextNode] != 0 : continue
        dfs(nextNode)

        dp[cur][0] += dp[nextNode][1]
        dp[cur][1] += min(dp[nextNode][0],dp[nextNode][1])

N = int(read())
adjs = [[] for _ in range(N+1)]
visited = [0 for _ in range(N+1)]
dp = [[0,0] for _ in range(N+1)]
for _ in range(N-1) :
    x,y = map(int,read().split())
    adjs[x].append(y)
    adjs[y].append(x)

dfs(1)

print(min(dp[1][0],dp[1][1]))