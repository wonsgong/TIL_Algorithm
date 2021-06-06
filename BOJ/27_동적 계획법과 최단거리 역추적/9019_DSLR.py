from collections import deque

# def 풀이과정 : 
    # 이전에 푼 숨바꼭질4 와 유사한 문제.
    # 경로를 출력 부분 생각해야되는 문제. 
    # rotate 이렇게 해줄 필요가 없었다...
    # L : int((cur%1000 * 10) + (cur//1000))
    # R : int((cur%10 * 1000) + (cur//10))
def rotate(x,dir) :

    x1 = x // 1000
    x2 = (x % 1000) // 100
    x3 = (x % 100) // 10
    x4 = x % 10
    if dir == 0 :
        return x2*1000+x3*100+x4*10+x1
    else :
        return x4*1000+x1*100+x2*10+x3

def getPath(a,b) :
    path = [b]
    while(a != b) :
        path.append(par[b])
        b = par[b]
    path = path[::-1]
    cmd = ["D","S","L","R"]
    for i in range(1,len(path)) :
        st = path[i-1]
        case = [2*st%10000, st - 1 if st != 0 else 9999, rotate(st, 0),rotate(st, 1)]
        for j in range(4) :
            if case[j] == path[i] :
                print(cmd[j],end='')
                break
    print()

def bfs(a,b) :
    q = deque()
    q.append(a)
    while q :
        cur = q.popleft()
        if cur == b :
            getPath(a,b)
            return 
        # D,S,L,R
        case = [2*cur%10000, cur - 1 if cur != 0 else 9999, rotate(cur, 0),rotate(cur, 1)]
        
        for i in case :
            if dp[i] > dp[cur] + 1 :
                dp[i] = dp[cur] + 1
                q.append(i)
                par[i] = cur

T = int(input())
case = [list(map(int,input().split())) for _ in range(T)]
for A,B in case :
    dp = [int(1e9) for _ in range(10000)]
    par = [0 for _ in range(10000)]
    dp[A] = 0
    bfs(A,B)

