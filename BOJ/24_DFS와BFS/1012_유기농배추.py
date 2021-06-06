# dfs 의 재귀 스택이 터지는 경우 -> bfs 로 짜자
# bfs 돌릴 때 visited 배열선언 -> 시간초과
# board 를 0으로 초기화
# dxs 선언시 [] 와 {} 구분 명확하게!

def bfs(x,y) :
    queue = [(x,y)]
    while queue :
        x,y = queue.pop(0)
        for (dx,dy) in zip(dxs,dys) :
            nx = x + dx
            ny = y + dy
            if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == 1 :
                board[nx][ny] = 0
                queue.append((nx,ny))


T = int(input())
dxs = [-1,1,0,0]
dys = [0,0,-1,1]

for _ in range(T) :
    M,N,K = map(int,input().split())
    board = [[0] * M for _ in range(N)]
    for _ in range(K) :
        x,y = map(int,input().split())
        board[y][x] = 1
    cnt = 0
    for i in range(N) :
        for j in range(M) :
            if board[i][j] == 1 :
                bfs(i,j)
                cnt += 1
                board[i][j] = 0

    print(cnt)
