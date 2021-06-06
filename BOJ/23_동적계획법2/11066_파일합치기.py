import sys

read = sys.stdin.readline

def merge(st,end) :
    global dp,sum

    if st == end : return 0
    if dp[st][end] != -1 : return dp[st][end]

    for i in range(st,end) :
        tmp = merge(st,i) + merge(i+1,end) + sum[end] - sum[st-1]
        if dp[st][end] == -1 or dp[st][end] > tmp : 
            dp[st][end] = tmp

    return dp[st][end]

N = int(read())
for _ in range(N) :
    K = int(read())
    Ns = list(map(int,read().split()))

    sum = [0]
    for n in Ns :
        sum.append(sum[-1]+n)

    dp = [[-1] * (K+1) for _ in range(K+1)]

    print(merge(1,K))

