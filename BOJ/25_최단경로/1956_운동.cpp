#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define MAXN 400
#define INF 987654321

vector<vector<int> > adj(MAXN+1, vector<int>(MAXN+1,INF));
int V,E,x,y,c;

void floyd() {
    for(int k=1; k<=V; k++) {
        for(int i=1; i<=V; i++) {
            for(int j=1; j<=V; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}

int main() {
    
    scanf("%d %d",&V,&E);
    for(int i=0; i<E; i++) {
        scanf("%d %d %d",&x,&y,&c);
        adj[x][y] = c;
    }
    floyd();

    int ans = INF;
    for(int i=1; i<=V; i++) {
        for(int j=1; j<=V; j++){
            if(i == j) {
                ans = min(ans,adj[i][j]);
            }
        }
    }
    if(ans == INF) printf("%d\n",-1);
    else printf("%d\n",ans);
    return 0;
}