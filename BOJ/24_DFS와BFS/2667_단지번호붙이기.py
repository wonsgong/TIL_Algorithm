# 얘도 dfs 돌면 되는건데 continue 생각을 잘못했네ㅠ
def dfs(x,y) :
    global cnt,N
    visited[x][y] = True
    for (dx,dy) in zip(dxs,dys) :
        if x+dx < 0 or x+dx >= N or y+dy < 0 or y+dy >= N : continue
        if board[x+dx][y+dy] == '1' and visited[x+dx][y+dy] == False:
            cnt += 1
            dfs(x+dx,y+dy)


N = int(input())
board = [input() for _ in range(N)]
visited = [[False] * N for _ in range(N)]
dxs = [-1,1,0,0]
dys = [0,0,-1,1]
danji = []
for x in range(N) :
    for y in range(N) :
        if board[x][y] =='1' and visited[x][y] == False :
            cnt = 1
            dfs(x,y)
            danji.append(cnt)

danji.sort()
print(len(danji))
for d in danji :
    print(d)