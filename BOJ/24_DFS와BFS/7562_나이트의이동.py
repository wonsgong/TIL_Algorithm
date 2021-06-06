from collections import deque

# 그냥 경우의 수만큼 bfs 돌면됨.
# 종료 조건을 board[tx][ty] != 0 으로만 하니까 큐가 전부 안도는 경우가 생겨버린다. 꼭 끝까지 돌고 나올수있게 짜자

def bfs() :

    q = deque()
    q.append((kx,ky))
    board[kx][ky] = 1
    ans = 987654321
    while q :
        cx,cy = q.popleft()
        if cx == tx and cy == ty and board[cx][cy] != 0:
            print(board[cx][cy])
            ans = min(ans,board[cx][cy])
        for dx,dy in zip(dxs,dys) :
            nx = cx + dx
            ny = cy + dy
            if 0 <= nx < I and 0 <= ny < I and (board[nx][ny] == 0 or board[nx][ny] > board[cx][cy] + 1):
                q.append((nx,ny))
                board[nx][ny] = board[cx][cy] + 1

    return ans-1  
dxs = [-2,-1,1,2,2,1,-1,-2]
dys = [1,2,2,1,-1,-2,-2,-1]
T = int(input())
for _ in range(T) :
    I = int(input())
    board = [[0] * I for _ in range(I)]
    kx,ky = map(int,input().split())
    tx,ty = map(int,input().split()) 

    if kx == tx and ky == ty :
        print(0)
    else :
        print(bfs())
