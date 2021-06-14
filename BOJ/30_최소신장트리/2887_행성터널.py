import sys

read = sys.stdin.readline

def find(x) :
    if par[x] == x : return par[x]
    else :
        par[x] = find(par[x])
        return par[x]

def merge(x,y) :
    p_x = find(x)
    p_y = find(y)
    if p_x == p_y : return
    par[p_x] = p_y

N = int(read())
pts = [list(map(int,read().split()))+[i] for i in range(N)]
par = [i for i in range(N)]
tree = []
for i in range(3) :
    pts.sort(key=lambda x:x[i])
    for j in range(1,N) :
        tree.append([abs(pts[j-1][i]-pts[j][i]),pts[j-1][3],pts[j][3]])

tree.sort()
cost = 0
for c,x,y in tree :
    if find(x) == find(y) : continue
    merge(x, y)
    cost += c
print(cost)