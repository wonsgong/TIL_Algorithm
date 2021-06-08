import sys
from collections import deque
read = sys.stdin.readline

def bfs(cur) :
    q = deque()
    q.append(cur)
    dist = [0 for _ in range(N+1)]

    while q :
        here = q.popleft()

        visited[here] = 1

        for n,d in adjs[here] :
            if visited[n] == 0 :
                q.append(n)
                dist[n] = dist[here] + d

    idx = dist.index(max(dist))
    
    return idx,dist[idx]


N = int(read())
adjs = [[] for _ in range(N+1)]
for _ in range(N-1) :
    x,y,c = map(int,read().split())

    adjs[x].append([y,c])
    adjs[y].append([x,c])

visited = [0 for _ in range(N+1)]
idx, _ = bfs(1)

visited = [0 for _ in range(N+1)]
_, ans = bfs(idx)

print(ans)