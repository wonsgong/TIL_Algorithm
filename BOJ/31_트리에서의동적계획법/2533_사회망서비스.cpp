#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAXN 1000000

using namespace std;

int N,x,y,visitied[MAXN+1],dp[MAXN+1][2];
vector<int> adjs[MAXN+1];

void dfs(int cur) {
    visitied[cur] = 1;

    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for(int i=0; i<adjs[cur].size(); i++) {
        int next = adjs[cur][i];
        if(visitied[next] != 0) continue;
        dfs(next);

        dp[cur][0] += dp[next][1];
        dp[cur][1] += min(dp[next][0],dp[next][1]);
    }
}

int main() {

    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d %d",&x,&y);
        adjs[x].push_back(y);
        adjs[y].push_back(x);
    }
    dfs(1);

    printf("%d\n",min(dp[1][0],dp[1][1]));
    
    return 0;
}