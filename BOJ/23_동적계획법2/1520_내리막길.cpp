#include <cstdio>
#include <iostream>
#include <string.h>

/*
    dp[x][y] = 0 으로 초기화 해주는 게 중요하다. -> 없으면 재귀돌때 -1 로 계속 더해짐ㅠㅠ 
    처음에 저거 빼먹었다가 += 이 아닌 줄 알고 헤맸다.
*/

using namespace std;

int N,M,cnt;
int maps[501][501], dp[501][501];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int dfs(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= M) return 0;
    if(x == N-1 && y == M-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for(int i=0; i<4; i++) {
        if(x+dx[i] < 0 || x+dx[i] >= N || y+dy[i] < 0 || y+dy[i] >= M) continue;
        if(maps[x][y] > maps[x+dx[i]][y+dy[i]]) 
            dp[x][y] += dfs(x+dx[i],y+dy[i]);
    }
    return dp[x][y];
}


int main() {
    
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d",&maps[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(0,0));

 
    return 0;

}
