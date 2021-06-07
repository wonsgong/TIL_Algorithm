import sys
from collections import deque

read = sys.stdin.readline

def bfs(cur) :
    q = deque()
    q.append(cur)
    dist = [0 for _ in range(V+1)]

    while q :
        here = q.popleft()
        visited[here] = 1

        for n,d in adjs[here] :
            if visited[n] == 0 :
                q.append(n)
                dist[n] = dist[here] + d

    retidx = 0
    ret = 0
    for i in range(1,V+1) :
        if ret < dist[i] :
            ret = dist[i]
            retidx = i

    return retidx, ret


V = int(read())
adjs = [[] for _ in range(V+1)]

for i in range(1,V+1) :
    line = list(map(int,read().split()))

    for j in range(1,len(line),2) :
        if line[j] == -1 : break
        adjs[line[0]].append([line[j],line[j+1]])


visited = [0 for _ in range(V+1)]
idx, _ = bfs(1)

visited = [0 for _ in range(V+1)]
_, ans = bfs(idx)

print(ans)


