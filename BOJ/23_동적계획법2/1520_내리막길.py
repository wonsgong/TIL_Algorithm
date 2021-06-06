import sys

read = sys.stdin.readline

def dfs(x,y) :
    global N,M,maps,dp,D
    if x < 0 or x >= N or y < 0 or y >= M : return 0
    if x == N-1 and y == M-1 : return 1
    if dp[x][y] != -1 : return dp[x][y]

    dp[x][y] = 0
    for dx, dy in D :
        if x+dx < 0 or x+dx >= N or y+dy < 0 or y+dy >= M : continue
        if maps[x][y] > maps[x+dx][y+dy] :
            dp[x][y] += dfs(x+dx,y+dy)
    
    return dp[x][y]


N,M = map(int,read().split())
maps = [list(map(int,read().split())) for _ in range(N)]
dp = [[-1] * M for _ in range(N)]
D = [(1,0),(-1,0),(0,1),(0,-1)]

print(dfs(0,0))