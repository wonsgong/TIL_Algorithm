from collections import deque

# 이동 할 때마다 경로를 저장하면 되는 거였어.!!!!
def bfs(a,b) :
    q = deque()
    q.append([a,""])
    cmd = ["D","S","L","R"]
    while q :
        cur,path = q.popleft()
        if cur == b :
            print(path)
            return 
        # D,S,L,R
        case = [2*cur%10000, cur - 1 if cur != 0 else 9999, 
                int((cur%1000 * 10) + (cur//1000)),
                int((cur%10 * 1000) + (cur//10))]

        for i in range(4) :
            if dp[case[i]] == 0 :
                dp[case[i]] = 1
                q.append([case[i],path+cmd[i]])

T = int(input())
case = [list(map(int,input().split())) for _ in range(T)]
for A,B in case :
    dp = [0 for _ in range(10000)]
    bfs(A,B)

