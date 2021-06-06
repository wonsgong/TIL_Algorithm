import sys

read = sys.stdin.readline
INF = int(1e9)

# 플로이드와샬 알고리즘은 출발-도착 > 출발 + 경유 + 도착 인 경우를 찾아주는 것
# 정점의 크기가 크면 할 수 없는 시간복잡도가 O(N^3) 인 알고리즘이다. 

def floyd() :
    for k in range(1,N+1) :
        for i in range(1,N+1) :
            for j in range(1,N+1) :
                if i == j : continue
                if adjs[i][j] > adjs[i][k] + adjs[k][j] :
                    adjs[i][j] = adjs[i][k] + adjs[k][j]



N = int(read())
M = int(read())
adjs = [[INF] * (N+1) for _ in range(N+1)]
for _ in range(M) :
    x,y,c = map(int,read().split())
    if adjs[x][y] > c :
        adjs[x][y] = c

floyd()

for i in range(1,N+1) :
    for j in range(1,N+1) :
        if adjs[i][j] == INF :
            print(0,end=' ')
        else :
            print(adjs[i][j],end=' ')
    print()