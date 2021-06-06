A = input()
B = input()

dp = [[0] * 1001 for _ in range(1001)]

ans = 0
for i in range(len(A)) :
    for j in range(len(B)) :
        if A[i] == B[j] :
            dp[i+1][j+1] = dp[i][j] + 1
            ans = max(ans,dp[i+1][j+1])
        else :
            dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j])

ret = ""
la = len(A); lb = len(B)

while dp[la][lb] != 0 :
    if dp[la][lb] == dp[la-1][lb] : la -= 1
    elif dp[la][lb] == dp[la][lb-1] : lb -= 1
    else :
        ret = A[la-1] + ret
        la-=1; lb-=1

print(ans)
print(ret)
