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

V,E = map(int,read().split())
par = [i for i in range(V+1)]
tree = []
for _ in range(E) :
    a,b,c = map(int,read().split())
    tree.append([c,a,b])

tree.sort()
cost = 0
for c,a,b in tree :
    if find(a) == find(b) : continue
    merge(a, b)
    cost += c
print(cost)
