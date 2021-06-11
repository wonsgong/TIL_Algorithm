#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define MAXN 500

using namespace std;

vector<int> adjs[MAXN+1];
bool visited[MAXN+1];
int N,M,x,y;

bool bfs(int st) {

    queue<int> q;
    q.push(st);
    int v = 0, e = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();

        if(visited[here]) continue;

        visited[here] = 1;
        v += 1;
        for(int i=0; i<adjs[here].size(); i++) {
            e += 1;
            q.push(adjs[here][i]);
        }
    }
    if(v-1 == e/2) return true;
    else return false;
}

int main() {
    int cnt = 0;
    while (1) {
        scanf("%d %d",&N,&M);
        if(N == 0 && M == 0) break;

        for(int i=0; i<=MAXN; i++) adjs[i].clear();
        memset(visited,false,sizeof(visited));

        for(int i=0; i<M; i++) {
            scanf("%d %d",&x,&y);
            adjs[x].push_back(y);
            adjs[y].push_back(x);
        }
        int tree = 0;
        for(int i=1; i<=N; i++) {
            if(visited[i]) continue;
            if(bfs(i)) tree+=1;
        }

        cnt += 1;
        if(tree == 0) printf("Case %d: No trees.\n",cnt);
        else if(tree == 1) printf("Case %d: There is one tree.\n",cnt);
        else printf("Case %d: A forest of %d trees.\n",cnt,tree);
    }
    return 0;
}