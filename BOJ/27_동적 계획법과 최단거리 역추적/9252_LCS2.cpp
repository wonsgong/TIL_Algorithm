#include <cstdio>
#include <string>
#include <iostream>

#define MAXN 1000

using namespace std;

string A,B;
int dp[MAXN+1][MAXN+1];

int main() {

    cin >> A >> B;
    int a = A.length(), b = B.length();

    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            if(A[i] == B[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
        }
    }
    string ans = "";
    while(dp[a][b] != 0) {
        if(dp[a][b] == dp[a-1][b]) a -= 1;
        else if(dp[a][b] == dp[a][b-1]) b -= 1;
        else {
            ans = A[a-1] + ans;
            a-=1; b-=1;
        }
    }
    cout << dp[A.length()][B.length()] << "\n" << ans << endl;
    return 0;
}