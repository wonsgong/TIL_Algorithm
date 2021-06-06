#include <cstdio>
#include <iostream>
#include <string.h>

/*
    경우 : 추 1개 올린경우 , 같은 곳에 올린 경우, 반대편에 올린 경우
    30개 추 500g -> 15000 / 주어질 값 40000 => 범위 벗어나는 경우 체크!
*/


using namespace std;

int N,M,G;
int chu[31], dp[31][15001];

void makeCombi(int cnt, int weight) {

    if(cnt > N) return ;
    if(dp[cnt][weight] != -1) return ;

    dp[cnt][weight] = 1;

    makeCombi(cnt+1,weight);
    makeCombi(cnt+1,weight+chu[cnt]);
    makeCombi(cnt+1,abs(weight-chu[cnt]));

}

int main() {

    
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",chu+i);
    memset(dp,-1,sizeof(dp));

    makeCombi(0,0);

    scanf("%d",&M);
    for(int i=0; i<M; i++) {
        scanf("%d",&G);
        if(G > 15000) printf("N ");
        else if(dp[N][G] == 1) printf("Y ");
        else printf("N ");
    }





    return 0;

}
