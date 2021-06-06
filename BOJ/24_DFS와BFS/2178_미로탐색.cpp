#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

/*
    숫자가 공백없이 한줄로 입력이 되서 들어오면 scanf("%1d") 로 입력받으면 숫자 하나씩 입력 가능.
*/


int N,M;
int board[101][101];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

void bfs() {

    queue<pair<int,int> > q;
    q.push(make_pair(0,0));

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0 <= nx && nx < N && 0<= ny && ny < M && board[nx][ny] == 1) {
                q.push(make_pair(nx,ny));
                board[nx][ny] = board[cx][cy] + 1;
            }
        }
    }
}


int main() {

    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) 
            scanf("%1d",&board[i][j]);

    bfs();

    cout << board[N-1][M-1] << endl;

    return 0;
}