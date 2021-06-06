from collections import deque
# DSLR 모범답안 방식으로 다시 풀어봄!
MAXN = 100000

def bfs() :
    q = deque()
    q.append([N,str(N)])

    while q : 
        cur,path = q.popleft()
        if cur == K :
            print(dp[K])
            print(path)
            break
        for i in [2*cur,cur-1,cur+1] :
            if 0 <= i <= MAXN and dp[i] > dp[cur] + 1 :
                dp[i] = dp[cur] + 1
                q.append([i,path+" "+str(i)])
    

N,K = map(int,input().split())
dp = [int(1e9) for _ in range(MAXN+1)]
move = [0 for _ in range(MAXN+1)]
dp[N] = 0

bfs()