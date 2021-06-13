import sys

sys.setrecursionlimit(int(1e9))
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

N,M = map(int,read().split())
par = [i for i in range(N+1)]
end = 0
for i in range(1,M+1) :
    x,y = map(int,read().split())
    if find(x) == find(y) and end == 0 :
        end = i
    
    merge(x, y)

print(end)