#include <iostream>

#define MAXN 1000000

using namespace std;

int N,M,cmd,x,y;
int par[MAXN+1];
int find(int x) {
    if(par[x] == x) return par[x];
    else return par[x] = find(par[x]);
}

void merge(int x, int y) {
    int p_x = find(x);
    int p_y = find(y);

    par[p_x] = p_y;
}

int main() {

    scanf("%d %d",&N,&M);
    for(int i=0; i<=N; i++) par[i] = i;
    for(int i=0; i<M; i++) {
        scanf("%d %d %d",&cmd,&x,&y);

        if(cmd == 0) merge(x,y);
        else {
            if(find(x) == find(y)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}