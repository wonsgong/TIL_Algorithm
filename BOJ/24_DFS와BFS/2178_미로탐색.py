# 얘도 하나씩 구분지어서 받으려면 board = [ ... for _ ] 가 아닌
# board.append(list(input())) 으로 해줘야 함 -> 구분지어서 받을 수 있음.
# 그리고 더해줄 수 있게 board[0][0] = 1 로 해줌. 
# 이하 같음.
def bfs() :
    queue = [(0,0)]
    while queue :
        cx,cy = queue.pop(0)
        for (dx,dy) in zip(dxs,dys) :
            nx = cx + dx
            ny = cy + dy
            if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == '1' :
                queue.append((nx,ny))
                board[nx][ny] = board[cx][cy] + 1

N,M = map(int,input().split())
#board = [input() for _ in range(N)]
board = []
for _ in range(N) :
    board.append(list(input()))
dxs = [1,0,-1,0]
dys = [0,1,0,-1]
board[0][0] = 1
bfs()
print(board)