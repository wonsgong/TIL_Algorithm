#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

/*
    단위 설정(범위) 를 잘 정해주십시다.
*/

#define MAX 800
#define INF 987654321
using namespace std;

int N,E,V1,V2,x,y,c;
vector<pair<int,int> > adjmat[MAX+1];
int dist[MAX+1];
int dji(int st,int end) {

    priority_queue<pair<int,int> > pq; // -cost , cur
    for(int i=0; i<=N; i++) dist[i] = INF;

    pq.push(make_pair(0,st));
    dist[st] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cost) continue;

        for(int i=0; i<adjmat[cur].size(); i++) {
            int next = adjmat[cur][i].first;
            int nextCost = cost + adjmat[cur][i].second;

            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push(make_pair(-nextCost,next));
            }
        }
    }
    return dist[end];
}

int main() {

    scanf("%d %d",&N,&E);
    for(int i=0; i<E; i++) {
        scanf("%d %d %d",&x,&y,&c);
        adjmat[x].push_back(make_pair(y,c));
        adjmat[y].push_back(make_pair(x,c));
    }
    scanf("%d %d",&V1,&V2);

    long long p1 = dji(1,V1); long long p2 = dji(V1,V2); long long p3 = dji(V2,N);
    long long q1 = dji(1,V2); long long q2 = dji(V2,V1); long long q3 = dji(V1,N);

    long long ans = min(p1+p2+p3,q1+q2+q3);

    if(ans >= INF) printf("%d\n",-1);
    else printf("%lld\n",ans);


}  