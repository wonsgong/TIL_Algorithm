import sys

read = sys.stdin.readline
INF = int(1e9)
#def 풀이과정 : 
    # path[i][j] : i 에서 j 로 가는 데 거쳐가는 경로(k)
    # 그 중에서도 가장 마지막 k 가 최단 경로.
    # 그거 이용해서 재귀로 경로 찾아서 출력해준다.
    # i - k - j 인 경우 (i,k) , (k,j) 를 구해주는 데
    # 경로 K는 (i,k) 와 (k,j) 를 구해주는 중간에 넣어주어야 순서가 맞다.

def getPath(i,j,K) :
    k = path[i][j][-1]
    if len(path[i][k]) != 0 :
        getPath(i, k, K)
    K.append(k)
    if len(path[k][j]) != 0 :
        getPath(k, j, K)

def floyd() :
    for k in range(1,N+1) :
        for i in range(1,N+1) :
            for j in range(1,N+1) :
                if adjs[i][j] > adjs[i][k] + adjs[k][j] :
                    adjs[i][j] = adjs[i][k] + adjs[k][j]
                    path[i][j].append(k)


N = int(read())
M = int(read())
adjs = [[INF] * (N+1) for _ in range(N+1)]
path = [[[] for _ in range(N+1)] for _ in range(N+1)]

for _ in range(M) :
    x,y,c = map(int,read().split())
    if adjs[x][y] > c :
        adjs[x][y] = c

floyd()
for i in range(1,N+1):
    for j in range(1,N+1) :
        if i == j : print(0,end=' ')
        elif adjs[i][j] == INF : print(0,end=' ')
        else : print(adjs[i][j],end=' ')
    print()

for i in range(1,N+1) :
    for j in range(1,N+1) :
        if i == j or adjs[i][j] == INF : print(0)
        elif len(path[i][j]) == 0 : print(2,i,j)
        else :
            K = [i]
            getPath(i, j,K)
            K.append(j)
            print(len(K),*K)            
