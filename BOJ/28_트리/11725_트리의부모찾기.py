from collections import deque
import sys
read = sys.stdin.readline

def bfs() :
    q = deque()
    q.append(1)

    while q :
        cur = q.popleft()
        if visited[cur] != 0 : continue
        visited[cur] = 1

        for ch in adjs[cur] :
            if par[ch] != 0 : continue
            par[ch] = cur
            q.append(ch)

N = int(read())
adjs = [[] for _ in range(N+1)]
par = [0 for _ in range(N+1)]
visited = [0 for _ in range(N+1)]
for _ in range(N-1) :
    x,y = map(int,read().split())
    adjs[x].append(y)
    adjs[y].append(x)

bfs()
for p in par[2:] :
    print(p)