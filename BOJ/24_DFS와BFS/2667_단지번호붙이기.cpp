#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int N,cnt;
bool visited[26][26];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
vector<string> board;

void dfs(int x, int y) {

    visited[x][y] = true;
    for(int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N)  continue;
        if(board[nx][ny] == '1' && visited[nx][ny] == false) {
            cnt += 1;
            dfs(nx,ny);
        }
    }
}   

int main() {

    cin >> N;
    string str;
    for(int i=0; i<N; i++) {
        cin >> str;
        board.push_back(str);
    }
    memset(visited,false,sizeof(visited));
    vector<int> ans;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == '1' && visited[i][j] == false) {
                cnt = 1;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}