import sys
from collections import deque
# queue 쓸 일 있으면 리스트로 구현하지 말고 deque 쓰세요... 
# 리스트로 구현하니까 너무 오래걸리네;;;;;;;;;;;

def bfs() :
    while q :
        cx,cy = q.popleft()
        for (dx,dy) in zip(dxs,dys) :
            nx = cx + dx
            ny = cy + dy
            if 0 <= nx < N and 0 <= ny < M and farm[nx][ny] == 0 :
                q.append((nx,ny))
                farm[nx][ny] = farm[cx][cy] + 1


M,N = map(int,input().split())
farm = [list(map(int,input().split())) for _ in range(N)]
dxs = [-1,1,0,0]
dys = [0,0,-1,1]
q = deque()
for i in range(N) :
    for j in range(M) :
        if farm[i][j] == 1:
            q.append((i,j))
bfs()

ans = 0
for i in range(N) :
    for j in range(M) :
        if farm[i][j] == 0 :
            print(-1)
            sys.exit(0)
        ans = max(ans,farm[i][j])
    
print(ans-1)
