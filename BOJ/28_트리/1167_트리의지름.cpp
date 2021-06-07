#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define MAXN 100000

using namespace std;

int V,visited[MAXN+1],dist[MAXN+1];
vector<pair<int,int> > adjs[MAXN+1];
pair<int,int> ans;

pair<int,int> bfs(int cur) {

    queue<int> q;
    q.push(cur);

    while (!q.empty()) {
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
    int retIdx = 0, ret = 0;
    for(int i=1; i<=V; i++) {
        if(ret < dist[i]) {
            ret = dist[i];
            retIdx = i;
        }
    }
    return make_pair(retIdx,ret);
}


int main() {

    scanf("%d",&V);
    for(int i=0; i<V; i++) {

        int x;
        scanf("%d",&x);
        while(1) {
            int y,c;
            scanf("%d",&y);
            if(y == -1) break;

            scanf("%d",&c);
            adjs[x].push_back(make_pair(y,c));
        }
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
/** getline 후 파싱하는 방법.
 * 파이썬하다가 하니까 빡시네
getline(cin,line);
istringstream ss(line);
string buffer;
vector<int> v; 
while(getline(ss,buffer,' ')) v.push_back(stoi(buffer));

for(int j=1; j<v.size(); j+=2) {
    if(v[j] == -1) break;
    adjs[v[0]].push_back(make_pair(v[j],v[j+1]));
}
**/