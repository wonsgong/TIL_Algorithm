#include <cstdio>
#include <iostream>
#include <string.h>

/* 
    연속되는 페이지라는 점 + sum을 통해 st-end 까지의 합을 구해놓는 점. -> 핵심 아이디어

*/
using namespace std;

int cost[501],sum[501];
int dp[501][501];
int N,K;

int merge(int st, int end) {

    if(st == end) return 0;
    if(dp[st][end] != -1) return dp[st][end];

    for(int i=st; i<end; i++) {
        int tmp = merge(st,i) + merge(i+1,end) + sum[end] - sum[st-1];
        if(dp[st][end] == -1 || dp[st][end] > tmp) dp[st][end] = tmp;
    }
    return dp[st][end];
} 

int main() {
    
    scanf("%d",&N);
    for(int i=0; i<N; i++) {

        memset(cost,0,sizeof(cost));
        memset(sum,0,sizeof(sum));
        memset(dp,-1,sizeof(dp));

        scanf("%d",&K);
        for(int j=1; j<=K; j++) {
            scanf("%d",cost+j);
            sum[j] = sum[j-1] + cost[j];
        }
        printf("%d\n",merge(1,K));
    }



    return 0;

}
