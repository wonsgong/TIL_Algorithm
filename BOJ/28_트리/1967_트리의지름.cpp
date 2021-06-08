#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define MAXN 10000

using namespace std;

vector<pair<int,int> > adjs[MAXN+1];
int N,x,y,c,visited[MAXN+1], dist[MAXN+1];
pair<int,int> ans;

pair<int,int> bfs(int cur) {

    queue<int> q;
    q.push(cur);

    while(!q.empty()) {

        int here = q.front();
        q.pop();

        visited[here] = 1;

        for(int i=0; i<adjs[here].size(); i++) {
            int next = adjs[here][i].first;
            int cost = adjs[here][i].second;
            if(visited[next] == 0) {
                q.push(next);
                dist[next] = dist[here] + cost;
            }
        }
    }
    int idx=0, ret = 0;
    for(int i=1; i<=N; i++) {
        if(ret < dist[i]) {
            ret = dist[i];
            idx = i;
        }
    }
    return make_pair(idx,ret);
}

int main() {

    scanf("%d",&N);
    for(int i=0; i<N-1; i++) {
        scanf("%d %d %d",&x,&y,&c);

        adjs[x].push_back(make_pair(y,c));
        adjs[y].push_back(make_pair(x,c));
    }
    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(dist));
    ans = bfs(1);

    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(dist));
    ans = bfs(ans.first);

    printf("%d\n",ans.second);


    return 0;
}
