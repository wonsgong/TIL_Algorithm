import sys
import heapq

read = sys.stdin.readline
INF = int(1e9)

# 정점의 개수가 적고, 간선의 길이가 많기 때문에 플로이드 와샬이 시간적으로 빠르다.

def floyd():
    for k in range(1,V+1) :
        for i in range(1,V+1) :
            for j in range(1,V+1) :
                if adj[i][j] > adj[i][k] + adj[k][j] :
                    adj[i][j] = adj[i][k] + adj[k][j]
        
V,E = map(int,read().split())
adj = [[INF] * (V+1) for _ in range(V+1)]
for _ in range(E):
    x,y,c = map(int,read().split())
    adj[x][y] = c

floyd()
ans = INF
for i in range(1,V+1) :
    for j in range(1,V+1) :
        if i == j :
            ans = min(ans,adj[i][j])
if ans == INF :
    print(-1)
else :
    print(ans)


