#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


#define MAX 2000
#define INF 987654321
typedef long long ll;
using namespace std;

int T,V,E,D,S,G,H;
vector<pair<int,int> > adjmat[MAX+1];
vector<int> dest;
ll dji(int st, int ed) {

    vector<int> dist(MAX+1,INF);
    priority_queue<pair<int,int> > pq;

    dist[st] = 0;
    pq.push(make_pair(0,st));
 
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;

        for(int i=0; i<adjmat[here].size(); i++) {
            int next = adjmat[here][i].first;
            int nextCost = cost + adjmat[here][i].second;

            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push(make_pair(-nextCost,next));
            }
        }
    }
    return dist[ed];
}

int main() {
    
    scanf("%d",&T);
    for(int i=0; i<T; i++) {
        
        scanf("%d %d %d",&V,&E,&D);
        scanf("%d %d %d",&S,&G,&H);
        
        for(int j=0; j<MAX+1; j++) adjmat[j].clear();
        dest.clear();
        for(int j=0; j<E; j++) {
            int x,y,c;
            scanf("%d %d %d",&x,&y,&c);
            adjmat[x].push_back(make_pair(y,c));
            adjmat[y].push_back(make_pair(x,c));
        }
        
        for(int j=0; j<D; j++) {
            int d;
            scanf("%d",&d);
            dest.push_back(d);
        }


        vector<int> ans;
        for(int j=0; j<D; j++) {
            ll P1 = dji(S,G) + dji(G,H) + dji(H,dest[j]);
            ll P2 = dji(S,H) + dji(H,G) + dji(G,dest[j]);
            ll mins = dji(S,dest[j]);
            if (mins == min(P1,P2)) ans.push_back(dest[j]);
        }
   
        sort(ans.begin(),ans.end());
        for(int j=0; j<ans.size(); j++) printf("%d ",ans[j]);
        printf("\n");

    }

    return 0;
}  