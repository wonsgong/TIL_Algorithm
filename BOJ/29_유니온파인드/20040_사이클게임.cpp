#include <iostream>

#define MAXN 500000

using namespace std;

int par[MAXN+1];
int N,M,x,y;

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
    
    scanf("%d %d",&N,&M);
    int ans = 0;
    for(int i=0; i<=N; i++) par[i] = i;
    for(int i=1; i<=M; i++) {
        scanf("%d %d",&x,&y);
        if(find(x) == find(y) && ans == 0) ans = i;
        merge(x,y);
    }
    printf("%d\n",ans);
    
    return 0;

}
