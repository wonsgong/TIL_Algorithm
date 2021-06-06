N = int(input())

dp = [0,0,1,1]
path = [0,1,1,1]

for i in range(4,N+1) :
    dp.append(dp[i-1] + 1)
    path.append(i-1)

    if i % 3 == 0 :
        if dp[i//3]+1 < dp[i] :
            dp[i] = dp[i//3]+1
            path[i] = i//3
    if i % 2 == 0 :
        if dp[i//2]+1 < dp[i] :
            dp[i] = dp[i//2]+1
            path[i] = i//2

print(dp[N])
print(N,end=' ')
while N != 1 :
    print(path[N],end=' ')
    N = path[N]
