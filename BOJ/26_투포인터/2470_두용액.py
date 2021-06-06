import sys

read = sys.stdin.readline

# a+b 도 음수일수 있음. 그걸 생각안했네

N = int(read())
nums = list(map(int,read().split()))

nums = sorted(nums)

st = 0
ed = N-1
a = int(1e9)
b = int(1e9)

while st < ed :
    if nums[st] + nums[ed] < 0 :
        if abs(a+b) > abs(nums[st]+nums[ed]) :
            a = nums[st]
            b = nums[ed]
        st += 1
    elif nums[st] + nums[ed] > 0 :
        if abs(a+b) > abs(nums[st]+nums[ed]):
            a = nums[st] 
            b = nums[ed]
        ed -= 1
    else :
        a = nums[st]
        b = nums[ed]
        break

print("{} {}".format(a,b))