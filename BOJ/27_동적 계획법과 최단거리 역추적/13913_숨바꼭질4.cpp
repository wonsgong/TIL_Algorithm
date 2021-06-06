#include <cstdio>
#include <iostream>
#include <queue>

/** 풀이 과정 
 * 최소 거리를 찾는 방법은 기존과 동일하게 경우 봐서 넣어줌.
 * 경로에 경우 현재 위치에서 온 위치(부모)를 저장해서 풀어줌.
 * **/

#define MAXN 100000

using namespace std;

int N,K;
int par[MAXN+1], dp[MAXN+1];

void getPath(int x) {
    int path[MAXN+1];
    int idx = 0;
    path[idx++] = x;

    while(x != N) {
        path[idx++] = par[x];
        x = par[x];
    }
    for(int i=idx-1; i>=0; i--) cout << path[i] << " ";
}

void bfs() {

    queue<int> q;
    q.push(N);

    while(!q.empty()) {
        int cur = q.front(); q.pop();        
        if(cur == K) {
            cout << dp[K] << endl;
            return ;
        }
        if(0<= 2*cur && 2*cur <= MAXN && dp[2*cur] > dp[cur] + 1) {
            q.push(2*cur);
            dp[2*cur] = dp[cur] + 1;
            par[2*cur] = cur;
        }
        if(0<= cur-1 && cur-1 <= MAXN && dp[cur-1] > dp[cur] + 1) {
            q.push(cur-1);
            dp[cur-1] = dp[cur] + 1;
            par[cur-1] = cur;
        }
        if(0<= cur+1 && cur+1 <= MAXN && dp[cur+1] > dp[cur] + 1) {
            q.push(cur+1);
            dp[cur+1] = dp[cur] + 1;
            par[cur+1] = cur;
        }
    }

}

int main() {

    cin >> N >> K;
    for(int i=0; i<=MAXN; i++) {
        par[i] = 0;
        dp[i] = 987654321;
    }
    dp[N] = 0;

    bfs();
    getPath(K);

    return 0;
}


