import sys

read = sys.stdin.readline

# 빼고 더하기 순서를 잘 생각해보자.

N,S = map(int,read().split())
nums = list(map(int, read().split()))
nums.append(0)
st = 0
ed = -1
sum_ = 0
ans = int(1e9)
while ed < N :
    if sum_ < S :
        ed += 1
        sum_ += nums[ed]
    else :
        ans = min(ans,(ed - st + 1))
        sum_ -= nums[st]
        st += 1

if ans == int(1e9) :
    print(0)
else :
    print(ans)



