#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 100000

using namespace std;

// 출력시 endl 쓰면 시간 초과 떠버린다. scanf/printf 쓰자

vector<int> adjs[MAXN+1];
int N,x,y,visited[MAXN+1],par[MAXN+1];

void bfs() {

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(visited[cur] != 0) continue;
        visited[cur] = 1;
        
        for(int i=0; i<adjs[cur].size(); i++) {
            int child = adjs[cur][i];
            if(par[child] != 0) continue;
            par[child] = cur;
            q.push(child);
        }
    }
}

int main() {

    scanf("%d",&N);
    for(int i=0; i<N-1; i++) {
        scanf("%d %d",&x,&y);
        adjs[x].push_back(y);
        adjs[y].push_back(x);
    }
    memset(visited,0,sizeof(visited));
    memset(par,0,sizeof(par));

    bfs();
    for(int i=2; i<=N; i++) printf("%d\n",par[i]);
    return 0;
}