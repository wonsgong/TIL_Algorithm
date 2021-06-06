
def dfs(cur) :
    visited[cur] = True
    print(cur,end=' ')
    for next in adjmat[cur] :
        if visited[next] == True :
            continue
        else :
            dfs(next)

def bfs(v) :
    queue = [v]
    while(len(queue) > 0) :
        cur = queue.pop(0)
        visited[cur] = True
        print(cur,end=' ')
        for next in adjmat[cur] :
            if visited[next] == True :
                continue
            else :
                if next not in queue :
                    queue.append(next)

N,M,V = map(int,input().split())
adjmat = [[] for _ in range(N+1)]
visited = [False for _ in range(N+1)]
for _ in range(M) :
    x,y = map(int,input().split())
    adjmat[x].append(y)
    adjmat[y].append(x)

for mat in adjmat :
    mat.sort()

dfs(V)
print()
visited = [False for _ in range(N+1)]
bfs(V)

