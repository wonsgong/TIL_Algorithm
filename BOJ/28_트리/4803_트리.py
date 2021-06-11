import sys
from collections import deque
read = sys.stdin.readline

def bfs(cur) :
    q = deque()
    q.append(cur)
    e,v = 0,0
    while q :
        here = q.popleft()
        if visited[here] == 1 : continue

        v += 1
        visited[here] = 1
        for n in adjs[here] :
            e += 1
            q.append(n)

    if e / 2 == v - 1 : return True
    else : return False
    
n,m = -1,-1
case = 0
while(1) :
    n,m = map(int,read().split())
    if n == 0 and m == 0 : break

    adjs = [[] for _ in range(n+1)]
    visited = [0 for _ in range(n+1)]
    for _ in range(m) :
        x,y = map(int, read().split())
        adjs[x].append(y)
        adjs[y].append(x)

    tree = 0
    for i in range(1,n+1) :
        if visited[i] == 1 : continue
        if bfs(i) : 
            tree += 1

    case += 1
    if tree == 0 :
        print("Case {}: No trees.".format(case))
    elif tree == 1 :
        print("Case {}: There is one tree.".format(case))
    else :
        print("Case {}: A forest of {} trees.".format(case,tree))

    