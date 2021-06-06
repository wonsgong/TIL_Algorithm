import sys
sys.setrecursionlimit(2000)

#def 풀이과정 : 
    # dp[i][j] : i,j = car1,2의 현재위치(최종사건해결 위치). 에서 최소 거리.
    # 즉 i,j 를 좌표로 계산하는게 아니라 인덱스로 생각해야 풀 수 있는 문제.
    # 경로를 계산하는 경우엔 이미 계산되어 있는 dp 를 이용해서 풀어주면 된다.
    # 재귀 최대 깊이인 1000을 넘어가기 때문에 깊이를 늘려주어야 풀 수 있다.


def getDist(x,y) :
    return abs(x[0]-y[0]) + abs(x[1]-y[1])

def dfs(carIdx1, carIdx2) :
    if carIdx1 == W or carIdx2 == W : return 0
    if dp[carIdx1][carIdx2] != -1 : return dp[carIdx1][carIdx2]

    nextIdx = max(carIdx1,carIdx2) + 1

    dist1 = getDist(car1[carIdx1], car1[nextIdx])
    dist2 = getDist(car2[carIdx2], car2[nextIdx])

    ret1 = dfs(nextIdx,carIdx2) + dist1
    ret2 = dfs(carIdx1,nextIdx) + dist2

    dp[carIdx1][carIdx2] = min(ret1,ret2)

    return dp[carIdx1][carIdx2]

def getPath(carIdx1, carIdx2) :
    if carIdx1 == W or carIdx2 == W : return 

    nextIdx = max(carIdx1,carIdx2) + 1

    dist1 = getDist(car1[carIdx1], car1[nextIdx])
    dist2 = getDist(car2[carIdx2], car2[nextIdx])

    ret1 = dfs(nextIdx,carIdx2) + dist1
    ret2 = dfs(carIdx1,nextIdx) + dist2

    if ret1 < ret2 :
        print(1)
        getPath(nextIdx, carIdx2)

    else :
        print(2)
        getPath(carIdx1, nextIdx)


N = int(input())
W = int(input())
car1 = [[1,1]]
car2 = [[N,N]]
for _ in range(W) :
    x,y = map(int,input().split())
    car1.append([x,y])
    car2.append([x,y])

dp = [[-1] * (W+1) for _ in range(W+1)]

print(dfs(0,0))
getPath(0,0)