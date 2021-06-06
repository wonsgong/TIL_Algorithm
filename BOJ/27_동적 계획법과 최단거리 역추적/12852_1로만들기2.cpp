#include <cstdio>

#define MAXN 1000000
int dp[MAXN+1], path[MAXN+1];
int N;
int main() {

    scanf("%d",&N);

    dp[0] = 0; path[0] = 0;
    dp[1] = 0; path[1] = 0;
    dp[2] = 1; path[2] = 1;
    dp[3] = 1; path[3] = 1;

    for(int i=4; i<=N; i++) {
        dp[i] = dp[i-1] + 1;
        path[i] = i-1;

        if(i % 3 == 0) {
            if(dp[i/3]+1 < dp[i]) {
                dp[i] = dp[i/3]+1;
                path[i] = i / 3;
            }
        }
        if(i % 2 == 0){
            if(dp[i/2]+1 < dp[i]) {
                dp[i] = dp[i/2]+1;
                path[i] = i / 2;
            }
        }
    }

    printf("%d\n",dp[N]);
    printf("%d ",N);
    while(N != 1) {
        printf("%d ",path[N]);
        N = path[N];
    }
    
    return 0;
}