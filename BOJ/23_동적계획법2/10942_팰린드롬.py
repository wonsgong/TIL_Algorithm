import sys

read = sys.stdin.readline

def getPal() : 
    global N,nums,dp

    for i in range(N) :
        dp[i][i] = 1
        left = i-1
        right = i+1
        while 0 <= left and right < N :
            if nums[left] != nums[right] : break
            dp[left][right] = 1
            left -= 1
            right += 1

    for i in range(N-1) :
        if nums[i] != nums[i+1] : continue
        left = i
        right = i+1
        while 0 <= left and right < N :
            if nums[left] != nums[right] : break
            dp[left][right] = 1
            left -= 1
            right += 1



N = int(read())
nums = list(map(int,read().split()))
dp = [[0] * N for _ in range(N)]
getPal()

M = int(read())
for _ in range(M) :
    S,E = map(int,read().split())
    print(dp[S-1][E-1])
