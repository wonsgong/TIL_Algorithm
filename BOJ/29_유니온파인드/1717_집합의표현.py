import sys

read = sys.stdin.readline
sys.setrecursionlimit(int(1e9))
def find(x) :
    if par[x] == x : return par[x]
    else : 
        par[x] = find(par[x])
        return par[x]

def merge(x,y) :
    p_x = find(x)
    p_y = find(y)

    par[p_x] = p_y



N,M = map(int,read().split())
par = [i for i in range(N+1)]
for _ in range(M) :
    cmd,x,y = map(int,read().split())

    if cmd == 0 : 
        merge(x,y)

    else :
        if find(x) == find(y) :
            print("YES")
        else : 
            print("NO")