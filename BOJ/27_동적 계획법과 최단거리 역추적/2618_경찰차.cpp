#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

#define MAXN 1000
vector<pair<int,int> > car1;
vector<pair<int,int> > car2;
int N,W,x,y,dp[MAXN+1][MAXN+1];

int getDist(pair<int,int> x, pair<int,int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int dfs(int carIdx1, int carIdx2) {
    if(carIdx1 == W || carIdx2 == W) return 0;
    if(dp[carIdx1][carIdx2] != -1) return dp[carIdx1][carIdx2];

    int nextIdx = max(carIdx1,carIdx2) + 1;

    int dist1 = getDist(car1[carIdx1],car1[nextIdx]);
    int dist2 = getDist(car2[carIdx2],car2[nextIdx]);

    int car1 = dfs(nextIdx,carIdx2) + dist1;
    int car2 = dfs(carIdx1,nextIdx) + dist2;

    dp[carIdx1][carIdx2] = min(car1,car2);

    return dp[carIdx1][carIdx2];

}
void getPath(int carIdx1, int carIdx2) {
    if(carIdx1 == W || carIdx2 == W) return ;

    int nextIdx = max(carIdx1,carIdx2) + 1;

    int dist1 = getDist(car1[carIdx1],car1[nextIdx]);
    int dist2 = getDist(car2[carIdx2],car2[nextIdx]);

    int car1 = dfs(nextIdx,carIdx2) + dist1;
    int car2 = dfs(carIdx1,nextIdx) + dist2;

    if(car1 < car2) {
        cout << 1 << endl;
        getPath(nextIdx,carIdx2);
    }
    else {
        cout << 2 << endl;
        getPath(carIdx1,nextIdx);
    }

}

int main() {

    memset(dp,-1,sizeof(dp));
    cin >> N >> W;
    car1.push_back(make_pair(1,1));
    car2.push_back(make_pair(N,N));

    for(int i=0; i<W; i++) {
        cin >> x >> y;
        car1.push_back(make_pair(x,y));
        car2.push_back(make_pair(x,y));
    }

    cout << dfs(0,0) << endl;
    getPath(0,0);
}