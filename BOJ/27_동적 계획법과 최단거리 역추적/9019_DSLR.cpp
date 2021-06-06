#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int T,A,B;
int dp[10001];

void bfs() {
    queue<pair<int,string> > q; // cur,path
    q.push(make_pair(A,""));
    string cmd[4] = {"D","S","L","R"};
    while(!q.empty()) {
        int cur = q.front().first;
        string path = q.front().second;
        q.pop();

        if(cur == B) {
            cout << path << endl;
            return ;
        }
        int DSLR[4] = {2*cur%10000, cur == 0 ? 9999 : cur-1, 
                        ((cur%1000)*10+(cur/1000)),
                        ((cur%10)*1000+(cur/10))};

        for(int i=0; i<4; i++) {
            if(dp[DSLR[i]] == 0 ){
                dp[DSLR[i]] = 1;
                q.push(make_pair(DSLR[i],path+cmd[i]));
            }
        }
    }
}

int main() {

    cin >> T;
    
    for(int i=0; i<T; i++) {
        cin >> A >> B;
        memset(dp,0,sizeof(dp));
        bfs();

    }


    return 0;
}