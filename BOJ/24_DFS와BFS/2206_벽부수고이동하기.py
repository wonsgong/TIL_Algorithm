from collections import deque

# bfs 2번 돌리는걸로 했는데 안된다.
# 결국 힌트 얻어서 품. -> 벽 뚫는걸 기억하는 배열로 만들어줘야대네.

def bfs() :

    visited = [[[0] * 2 for _ in range(M)] for _ in range(N)]
    q = deque()
    q.append((0,0,1))
    visited[0][0][1] = 1

    while q : 
        cx,cy,t = q.popleft()
        if cx == N-1 and cy == M-1 :
            return visited[cx][cy][t]
        for dx,dy in zip(dxs,dys) :
            nx = cx + dx
            ny = cy + dy
            if 0 <= nx < N and 0 <= ny < M :
                if maps[nx][ny] == 0 and visited[nx][ny][t] == 0 :
                    q.append((nx,ny,t))
                    visited[nx][ny][t] = visited[cx][cy][t] + 1
                elif maps[nx][ny] == 1 and t == 1 :
                    q.append((nx,ny,0))
                    visited[nx][ny][0] = visited[cx][cy][t] + 1

    return -1

maps = []
N,M = map(int,input().split()) 
for _ in range(N) :
    # maps.append(list(map(int,list(input().strip()))))
    maps.append(list(map(int, list(input().strip()))))

dxs = [-1,1,0,0]
dys = [0,0,-1,1]

print(bfs())