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

N = int(read())
pt = [tuple(map(float,read().split())) for _ in range(N)]
par = [i for i in range(N)]
tree = []
for i in range(N) :
    for j in range(i+1,N) :
        tree.append([dist(pt[i],pt[j]),i,j])

tree.sort()
cost = 0
for c,a,b in tree :
    if find(a) == find(b) : continue
    merge(a, b)
    cost += c
print(round(cost,2))
