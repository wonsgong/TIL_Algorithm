import sys
from collections import deque

read = sys.stdin.readline
def find(x) :
    if par[x] == x : return par[x]
    else :
        par[x] = find(par[x])
        return par[x]

def merge(x,y) :
    p_x = find(x)
    p_y = find(y)
    if p_x == p_y : return
    par[p_x] = p_y

def bfs(x,y,n) :
    q = deque()
    q.append((x,y))
    while q :
        cx,cy = q.popleft()

        if visited[cx][cy] == 1 : continue

        visited[cx][cy] = 1
        land[n].append([cx,cy])
        for dx,dy in [[-1,0],[1,0],[0,-1],[0,1]] :
            nx = cx + dx
            ny = cy + dy
            if 0 <= nx < N and 0 <= ny < M and maps[nx][ny] == 1 and visited[nx][ny] == 0:
                q.append([nx,ny])

def check(ix,iy,jx,jy) :
    st,ed = -1,-1
    if ix == jx :
        if iy < jy : st,ed = iy,jy
        else : st,ed = jy,iy
        for i in range(st+1,ed) :
            if maps[ix][i] == 1 : return False
        return True
    else :
        if ix < jx : st,ed = ix,jx
        else : st,ed = jx,ix
        for i in range(st+1,ed) :
            if maps[i][iy] == 1 : return False
        return True


N,M = map(int,read().split())
maps = [list(map(int,read().split())) for _ in range(N)]
visited = [[0] * M for _ in range(N)]
land = [[] for _ in range(6)]
landN = 0
for i in range(N) :
    for j in range(M) :
        if maps[i][j] == 1 and visited[i][j] == 0:
            bfs(i,j,landN)
            landN += 1

tree = []
for i in range(landN) :
    for j in range(i+1,landN) :        
        for ix,iy in land[i] :
            for jx,jy in land[j] :
                if ix == jx and abs(iy-jy)-1 > 1 and check(ix, iy, jx, jy) :
                    tree.append([abs(iy-jy)-1,i,j])
                if iy == jy and abs(ix-jx)-1 > 1 and check(ix, iy, jx, jy) :
                    tree.append([abs(ix-jx)-1,i,j])

par = [i for i in range(landN)]
tree.sort()
cost = 0
connect = 0
for c,x,y in tree :
    if find(x) == find(y) : continue
    merge(x,y)
    connect += 1
    cost += c

if connect == landN - 1 : print(cost)
else : print(-1)

