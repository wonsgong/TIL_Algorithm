#include <iostream>

#define MAXN 200
#define MAXM 1000
using namespace std;
int adjs[MAXN+1][MAXN+1], par[MAXN+1], path[MAXM+1];
int N,M,x;

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
    for(int i=0; i<=N; i++) par[i] = i;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&x);
            if(x == 1) merge(i,j);
        }
    }
    for(int i=0; i<M; i++) {
        scanf("%d",path+i);
    }
    for(int i=1; i<M; i++) {
        if(find(path[i-1]) != find(path[i])) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;

}
