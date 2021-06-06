
# def 풀이과정 :
    # O(N^2)으로 LIS 출력하기.
N = int(input())
nums = list(map(int,input().split()))

dp = [1 for _ in range(N)]
lis = [[n] for n in nums]

for i in range(N) :
    for j in range(i) :
        if nums[i] > nums[j] :
            if dp[j]+1 > dp[i] :
                dp[i] = dp[j] + 1
                lis[i] = lis[j] + [nums[i]]
cnt = 0
flag = 0
for i in range(N) :
    if cnt < dp[i] :
        flag = i
        cnt = dp[i]

print(cnt)
print(*lis[flag])