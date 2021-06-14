#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M, landN, maps[11][11], par[11];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
bool visited[11][11];
vector<pair<int,pair<int,int> > > tree;
vector<pair<int,int> >land[7];

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

void bfs(int x, int y, int n) {
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        if(visited[cx][cy]) continue;

        visited[cx][cy] = true;
        land[n].push_back(make_pair(cx,cy));

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M && maps[nx][ny] == 1 && !visited[nx][ny]) {
                q.push(make_pair(nx,ny));
            }
        }


    }
}

int getDist(int x1, int y1, int x2, int y2) {
    int st,ed,dist=0;
    if(x1 == x2) {
        if(y1 < y2) {st = y1; ed = y2;}
        else {st = y2; ed = y1;}
        for(int i=st+1; i<ed; i++) {
            if(maps[x1][i] == 0) dist += 1;
            else return -1;
        }
    }
    else {
        if(x1 < x2) {st = x1; ed = x2;}
        else {st = x2; ed = x1;}
        for(int i=st+1; i<ed; i++) {
            if(maps[i][y1] == 0) dist += 1;
            else return -1;
        }
    }
    return dist;
}

int main() {

    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d",&maps[i][j]);
        }
    }
    memset(visited,false,sizeof(visited));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(maps[i][j] == 1 && !visited[i][j]) {
                bfs(i,j,landN);
                landN += 1;
            }
        }
    }
    for(int i=0; i<landN; i++) {
        for(int j=i+1; j<landN; j++) {

            for(int k=0; k<land[i].size(); k++) {
                for(int t=0; t<land[j].size(); t++){
                    if(land[i][k].first == land[j][t].first) {
                        int dist = getDist(land[i][k].first,land[i][k].second,land[j][t].first,land[j][t].second);
                        if(dist > 1) tree.push_back(make_pair(dist,make_pair(i,j)));
                    }
                    if(land[i][k].second == land[j][t].second) {
                        int dist = getDist(land[i][k].first,land[i][k].second,land[j][t].first,land[j][t].second);
                        if(dist > 1) tree.push_back(make_pair(dist,make_pair(i,j)));
                    }
                }
            }
        }
    }
    sort(tree.begin(),tree.end());
    for(int i=0; i<landN; i++) par[i] = i;
    int cost=0, bridge=0;
    for(int i=0; i<tree.size(); i++) {
        int c = tree[i].first;
        int x = tree[i].second.first;
        int y = tree[i].second.second;

        if(find(x) == find(y)) continue;
        merge(x,y);
        cost += c;
        bridge += 1;
    }
    if(landN-1 == bridge) printf("%d\n",cost);
    else printf("%d\n",-1);
}