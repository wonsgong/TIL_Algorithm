# 단순히 dfs 돌면서 cnt 세주면 되는 문제.
def dfs(cur) :
    global cnt
    visited[cur] = True
    for next in adjmat[cur] :
        if visited[next] != True:
            cnt += 1
            dfs(next)

N = int(input())
V = int(input())
adjmat = [[] for _ in range(N+1)]
for _ in range(V) :
    x,y = map(int,input().split())
    adjmat[x].append(y)
    adjmat[y].append(x)

cnt = 0
visited = [False for _ in range(N+1)]
dfs(1)
print(cnt)
