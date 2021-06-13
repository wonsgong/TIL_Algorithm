import sys
import math
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

def dist(x,y) :
    return math.sqrt((x[0]-y[0])**2 + (x[1]-y[1])**2)
N,M = map(int,read().split())
pts = [tuple(map(int,read().split())) for _ in range(N)]
tree = []
for i in range(N) :
    for j in range(i+1,N) :
        tree.append([dist(pts[i],pts[j]),i+1,j+1])
par = [i for i in range(N+1)]
for _ in range(M) :
    x,y = map(int,read().split())
    merge(x, y)

tree.sort()
cost = 0
for c,x,y in tree :
    if find(x) == find(y) : continue
    merge(x, y)
    cost += c
print("{:.2f}".format(cost))