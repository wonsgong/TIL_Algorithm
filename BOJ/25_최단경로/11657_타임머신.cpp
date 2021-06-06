#include <cstdio>
#include <iostream>
#include <vector>

/* 
    bellman dist 를 int 로 해줬더니 오버플로우때메 출력초과가 되버림.
    -> 단위 꼭 잘 생각합시다.
*/

#define MAX 500
#define INF 987654321
using namespace std;

int N,M;
vector<pair<int, pair<int,int> > > adjmat;
vector<long long> dist(MAX+1,INF);

bool bellman() {
    bool isCycle = false;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<M; j++) {
            int from = adjmat[j].first;
            int to = adjmat[j].second.first;
            int cost = adjmat[j].second.second;

            if(dist[from] == INF) continue;
            if(dist[to] > dist[from] + cost) {
                if(i == N) isCycle = true;
                dist[to] = dist[from] + cost;
            }
        }
    }
    return !isCycle;
}


int main() {
    int x, y, c;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++){
        scanf("%d %d %d", &x, &y, &c);
        adjmat.push_back(make_pair(x, make_pair(y, c)));
    }
    dist[1] = 0;
    if (bellman()){
        for (int i = 2; i <= N; i++){
            if (dist[i] == INF) printf("-1\n");
            else printf("%d\n", dist[i]);
        }
    }
    else
        printf("-1\n");
}