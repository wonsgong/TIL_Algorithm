import sys

read = sys.stdin.readline

def getCase(cnt, weight) :
    global N,chu,dp

    if cnt > N : return 0
    if dp[cnt][weight] != -1 : return 0

    dp[cnt][weight] = 1
    getCase(cnt+1,chu[cnt])
    getCase(cnt+1,weight+chu[cnt])
    getCase(cnt+1,abs(weight-chu[cnt]))



N = int(read())
chu = list(map(int,read().split()))
chu.append(0)
M = int(read())
nums = list(map(int,read().split()))

dp = [[-1] * 15001 for _ in range(31)]
getCase(0,0)

for n in nums :
    if n > 15000 : 
        print("N",end=' ')
    elif dp[N][n] == 1 : 
        print("Y",end=' ')
    else :
        print("N",end=' ')
