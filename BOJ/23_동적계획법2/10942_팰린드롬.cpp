#include <cstdio>
#include <iostream>
#include <string.h>

/*
    팰린드롬이 되는 경우 : 1 2 1 or 1 2 2 1.
    즉, dp[st][ed] 팰린드롬일때 num[st-1] = num[ed+1] -> dp[st-1][ed+1] 도 팰린드롬임. 
*/

using namespace std;

int N,M,S,E;
int nums[2001], dp[2001][2001];

void getPal() {
    for(int i=0; i<N; i++) {
        dp[i][i] = 1;
        int left = i-1, right = i+1;
        while(0 <= left && right < N) {
            if(nums[left] != nums[right]) break;
            dp[left][right] = 1;
            left--;
            right++;
        }
    }
    for(int i=0; i<N-1; i++) {
        if(nums[i] != nums[i+1]) continue;
        int left = i, right = i+1;
        while(0 <= left && right < N) {
            if(nums[left] != nums[right]) break;
            dp[left][right] = 1;
            left--;
            right++;
        }
    }
}

int main() {
   
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",nums+i);
    memset(dp,0,sizeof(dp));
    getPal();

    
    scanf("%d",&M);
    for(int i=0; i<M; i++) {
        scanf("%d %d",&S,&E);
        printf("%d\n",dp[S-1][E-1]);
    }

    return 0;

}
