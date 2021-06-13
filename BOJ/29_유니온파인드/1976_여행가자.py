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
M = int(read())
par = [i for i in range(N+1)]
adjs = []
for _ in range(N) :
    adjs.append(list(map(int,read().split())))
path = list(map(int,read().split()))

for i in range(N) :
    for j in range(N) :
        if adjs[i][j] == 1 :
            merge(i+1,j+1)

for i in range(1,len(path)) :
    if find(path[i-1]) != find(path[i]) :
        print("NO")
        sys.exit()

print("YES")