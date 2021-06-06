import sys
from collections import deque

def bfs() :
    while q :
        ch,cx,cy = q.popleft()

        for (dh,dx,dy) in zip(dhs,dxs,dys) :
            nh = ch + dh
            nx = cx + dx
            ny = cy + dy

            if 0 <= nh < H and 0 <= nx < N and 0 <= ny < M and farm[nh][nx][ny] == 0 :
                q.append((nh,nx,ny))
                farm[nh][nx][ny] = farm[ch][cx][cy] + 1
                

M,N,H = map(int,input().split())
farm = []
for _ in range(H) :
    farm.append([list(map(int,input().split())) for _ in range(N)])

dhs = [1,-1,0,0,0,0]
dxs = [0,0,-1,1,0,0]
dys = [0,0,0,0,-1,1]

q = deque()
for h in range(H) :
    for x in range(N) :
        for y in range(M) :
            if farm[h][x][y] == 1 :
                q.append((h,x,y))


bfs()

ans = 0
for h in range(H) :
    for x in range(N) :
        for y in range(M) :
            if farm[h][x][y] == 0 :
                print(-1)
                sys.exit(0)
            
            ans = max(ans,farm[h][x][y])

print(ans-1)