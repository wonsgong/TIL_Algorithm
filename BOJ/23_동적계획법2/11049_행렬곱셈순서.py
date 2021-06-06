import sys

read = sys.stdin.readline

def multi(st, end) :
    global dp,mat

    if st == end : return 0
    if dp[st][end] != -1 : return dp[st][end]

    for i in range(st,end) :
        tmp = multi(st,i) + multi(i+1,end) + (mat[st][0] * mat[i+1][0] * mat[end][1])
        if dp[st][end] == -1 or dp[st][end] > tmp :
            dp[st][end] = tmp
    
    return dp[st][end]


N = int(read())
mat = [list(map(int,read().split())) for _ in range(N)]
dp = [[-1] * N for _ in range(N)]
print(multi(0,N-1))

