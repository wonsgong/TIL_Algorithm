#include <cstdio>
#include <iostream>
#include <string.h>

/*
    dp[i][j] : i번째 앱에서 비용 j 를 썼을 때 얻을 수 있는 memory
    처음엔 dp[m] : m 메모리를 사용해서 얻을 수 있는 비용. 으로했는데 안댐.ㅜ
    확실히 dp 문제는 무엇을 메모이제이션 할 지가 가장 중요한 문제인것같다.
*/

#define MAXN 100

using namespace std;

int N,M,ans;
int memory[MAXN+1], cost[MAXN+1], dp[MAXN+1][MAXN*MAXN+1];

int main() {

    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) scanf("%d",memory+i);
    for(int i=1; i<=N; i++) scanf("%d",cost+i);

    ans = 987654321;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=MAXN*MAXN; j++) {

            if(j >= cost[i])
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-cost[i]]+memory[i]);
            else 
                dp[i][j] = dp[i-1][j];
            
            if(dp[i][j] >= M) ans = min(ans,j);
        }
    }
    printf("%d\n",ans);


    return 0;

}
