#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

/** 
 * 같은 방식으로 푸는데 path 출력 부분에서 오답이 되어버린다.
 * 왜 구럴까
**/

#define MAXN 100000
#define INF 987654321
using namespace std;

vector<pair<int,int> > adjs[MAXN+1];
int dist[MAXN+1],par[MAXN+1];
int N,M,x,y,c,st,ed;

int getLen(string s) {
    int ret = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]== ' ') continue;
        ret += 1;
    }
    return ret;
}

void dji() {

    // priority_queue<pair<int,pair<int,string> > > pq; // -cost, here, path
    // pq.push(make_pair(0,make_pair(st,to_string(st))));
    priority_queue<pair<int,int> > pq; // -cost , here
    pq.push(make_pair(0,st));
    dist[st] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        // string path = pq.top().second.second;
        pq.pop();
        // if(here == ed) {
        //     cout << cost << "\n" << getLen(path) << "\n" << path << "\n";
        //     return ;
        // }
        if(dist[here] < cost) continue;

        for(int i=0; i<adjs[here].size(); i++) {
            int next = adjs[here][i].first;
            int nextCost = cost + adjs[here][i].second;

            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push(make_pair(-nextCost,next));
                par[next] = here;
                // pq.push(make_pair(-nextCost,make_pair(next,path+" "+to_string(next))));
            }
        }
    }
    vector<int> path;
    int tmp = ed;
    path.push_back(ed);
    while(st != tmp) {
        path.push_back(par[tmp]);
        tmp = par[tmp];
    }
    cout << dist[ed] << "\n" << path.size() << "\n";
    for(int i=path.size()-1; i>=0; i--) cout << path[i] << " ";
    cout << "\n";
}


int main() {

    cin >> N >> M;
    for(int i=0; i<=MAXN; i++) { dist[i] = INF; par[i] = 0; }
    for(int i=0; i<M; i++) {
        cin >> x >> y >> c;
        adjs[x].push_back(make_pair(y,c));
    }
    cin >> st >> ed;
    dji();
    return 0;
}
