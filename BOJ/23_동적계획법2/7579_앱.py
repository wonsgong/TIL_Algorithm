import sys

read = sys.stdin.readline

N,M = map(int,read().split())
memorys = list(map(int,read().split()))
costs = list(map(int,read().split()))
dp = [[0] * 10001 for _ in range(101)]
ans = 987654321

for i , (memory, cost) in enumerate(zip(memorys,costs),start=1) :
    for c in range(1,10001) :
        if  c >= cost :
            dp[i][c] = max(dp[i-1][c],dp[i-1][c-cost]+memory)
        else :
            dp[i][c] = dp[i-1][c]


        if dp[i][c] >= M :
            ans = min(ans,c)

print(ans)


