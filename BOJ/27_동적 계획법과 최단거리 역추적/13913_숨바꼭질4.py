from collections import deque

MAXN = 100000



def getPath(x) :
    path = [K]
    while x != N :
        path.append(move[x])
        x = move[x]

    print(*path[::-1])

def bfs() :
    q = deque()
    q.append(N)

    while q : 
        cur = q.popleft()
        if cur == K :
            print(dp[K])
            break
        for i in [2*cur,cur-1,cur+1] :
            if 0 <= i <= MAXN and dp[i] > dp[cur] + 1 :
                dp[i] = dp[cur] + 1
                q.append(i)
                move[i] = cur
    

N,K = map(int,input().split())
dp = [int(1e9) for _ in range(MAXN+1)]
move = [0 for _ in range(MAXN+1)]
dp[N] = 0

bfs()
getPath(K)