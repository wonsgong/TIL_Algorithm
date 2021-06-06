from collections import deque

# 배열의 크기를 둘 중 더 큰 것으로 잡은게 잘못한거였다.
# 2배로 건너뛰어서 가면 되는 경우ㅜ
def bfs() :
    global N,M
    q = deque()
    q.append(N)

    while q :
        cur = q.popleft()
        if 0 <= 2*cur < len(board) and board[2*cur] == 0 :
            q.append(2*cur)
            board[2*cur] = board[cur] + 1
        if 0 <= cur-1 < len(board) and board[cur-1] == 0 :
            q.append(cur-1)
            board[cur-1] = board[cur] + 1
        if 0 <= cur+1 < len(board) and board[cur+1] == 0 :
            q.append(cur+1)
            board[cur+1] = board[cur] + 1

N,M = map(int,input().split())
board = [0 for _ in range(100001)]
board[N] = 1
bfs()

print(board[M]-1)