#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 20000
#define INF 987654321
using namespace std;

int V,E,K,x,y,c;
vector<pair<int,int> > adjmat[MAX+1];
vector<int> dist(MAX+1,INF);

void dji(int st) {

    priority_queue<pair<int,int> > pq; // -cost,cur
    pq.push(make_pair(0,st));
    dist[st] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost) continue;

        for(int i=0; i<adjmat[cur].size(); i++) {
            int next = adjmat[cur][i].first;
            int nextCost = cost + adjmat[cur][i].second;

            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push(make_pair(-nextCost,next));
            }
        }
    }
}

int main() {

    scanf("%d %d",&V,&E);
    scanf("%d",&K);

    for(int i=0; i<E; i++) {
        scanf("%d %d %d",&x,&y,&c);
        adjmat[x].push_back(make_pair(y,c));
    }
    dji(K);

    for(int i=1; i<=V; i++) {
        if(dist[i] == INF) {
            printf("INF\n");
        }
        else {
            printf("%d\n",dist[i]);
        }
    }

}  