#include <iostream>
#define MAXN 1000

int T,N,M,a,b;
int par[MAXN+1];

int find(int x) {
    if(par[x] == x) return par[x];
    else return par[x] = find(par[x]);
}

void merge(int x, int y) {
    int p_x = find(x);
    int p_y = find(y);
    if(p_x == p_y) return ;
    par[p_x] = p_y;    
}

int main() {

    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&N,&M);
        int cnt = 0;
        for(int i=0; i<=N; i++) par[i] = i;
        for(int i=0; i<M; i++) {
            scanf("%d %d",&a,&b);
            if(find(a) == find(b)) continue;
        
            merge(a,b);
            cnt += 1;
        }
        printf("%d\n",cnt);
    }
    return 0;
}