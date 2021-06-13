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

T = int(read())
for _ in range(T) :
    N,M = map(int,read().split())
    par = [i for i in range(N+1)]
    cnt = 0
    for _ in range(M) :
        a,b = map(int,read().split())
        if find(a) == find(b) : continue
        merge(a,b)
        cnt += 1
    print(cnt)
