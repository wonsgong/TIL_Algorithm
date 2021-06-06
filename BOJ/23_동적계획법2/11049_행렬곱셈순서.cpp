#include <cstdio>
#include <iostream>
#include <string.h>

/*  
    11066 파일 합치기와 동일한 문제.
*/
using namespace std;

int N;
int mat[501][2], dp[501][501];

int multi(int st, int end) {

    if(st == end) return 0;
    if(dp[st][end] != -1) return dp[st][end];

    for(int i=st; i<end; i++) {
        int tmp = multi(st,i) + multi(i+1,end) + (mat[st][0] * mat[i+1][0] * mat[end][1]);
        if(dp[st][end] == -1 || dp[st][end] > tmp) dp[st][end] = tmp;
    }
    return dp[st][end];
}


int main() {
    
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d %d",&mat[i][0],&mat[i][1]);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",multi(0,N-1));


    return 0;

}
