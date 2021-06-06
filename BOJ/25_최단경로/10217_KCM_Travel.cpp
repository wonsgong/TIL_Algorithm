#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    다익스트라로 풀수 있다!!! -> dist 배열을 잘 구현해줘야함.
    43-47 : 적은 예산으로 적은 시간이면 이후에 예산을 더썼을 때도 돌 필요 없이 만들어줍시다.
*/

#define MAXN 100
#define MAXM 100000
#define INF 987654321
vector<pair<int,pair<int,int> > > adjs[MAXN+1];
int dist[MAXN+1][MAXM+1];
int T,N,M,K,u,v,c,d;

int dji() {
    for(int i=0; i<=N; i++) {
        for(int j=0; j<=M; j++){
            dist[i][j] = INF;
        }
    }
    dist[1][0] = 0;
    priority_queue<pair<int, pair<int,int> > > pq; // time, cost, here
    pq.push(make_pair(0,make_pair(0,1)));

    while(!pq.empty()) {
        int time = -pq.top().first;
        int cost = pq.top().second.first;
        int here = pq.top().second.second;
        pq.pop();
        if(dist[here][cost] < time) continue;

        for(int i=0; i<adjs[here].size(); i++) {
            int next = adjs[here][i].first;
            int nextCost = cost + adjs[here][i].second.first;
            int nextTime = time + adjs[here][i].second.second;
            
            if (nextCost > M) continue;
            if(dist[next][nextCost] > nextTime) {
                for(int j=nextCost; j<=M; j++){
                    if(dist[next][j] > nextTime){
                        dist[next][j] = nextTime;
                    }
                }
                pq.push(make_pair(-nextTime,make_pair(nextCost,next)));
            } 
        }
    }
    return dist[N][M];
}

int main() {
    
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&N,&M,&K);
        for(int i=0; i<=MAXN; i++) adjs[i].clear();
        for(int i=0; i<K; i++) {
            scanf("%d %d %d %d",&u,&v,&c,&d);
            adjs[u].push_back(make_pair(v, make_pair(c,d)));
        }
        int ans = dji();
        if(ans == INF) printf("Poor KCM\n");
        else printf("%d\n",ans);
    }


    return 0;
}