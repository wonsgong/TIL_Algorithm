import sys

read = sys.stdin.readline

#def 풀이과정 :
    # O(NlogN) LIS 구하기
    # 이분 탐색 통해서 lower_bound 구해서 풀어줌.

def bisrch(dp,n) :
    left = 0; right = len(dp)
    while(left <= right) :
        mid = (left+right) // 2
        if dp[mid] < n :
            left = mid + 1
        else :
            right = mid - 1
    return right + 1


N = int(read())
nums = list(map(int,read().split()))
dp = []
idxs = []
for i in range(N) :
    if not dp or dp[-1] < nums[i] :
        dp.append(nums[i])
        idxs.append(len(dp)-1)
    else :
        idx = bisrch(dp, nums[i])
        dp[idx] = nums[i]
        idxs.append(idx)

ans = []
tmp = len(dp)-1
for i in range(N-1,-1,-1):
    if idxs[i] == tmp :
        ans.append(nums[i])
        tmp -= 1

print(len(ans))
print(*reversed(ans))