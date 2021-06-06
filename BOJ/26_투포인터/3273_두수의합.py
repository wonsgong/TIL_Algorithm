import sys

read = sys.stdin.readline

# 전형적인 투 포인터 문제.

N = int(read())
nums = list(map(int,read().split()))
X = int(read())

nums = sorted(nums)

st = 0
ed = N-1
ans = 0

while st < ed :
    if nums[st] + nums[ed] < X :
        st += 1
    elif nums[st] + nums[ed] > X :
        ed -= 1
    else :
        ans += 1
        st += 1
        ed -= 1

print(ans)
