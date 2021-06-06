#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>  
#include <string.h>

#define MAX 1000
using namespace std;

int N,M;
int board[MAX+1][MAX+1], visited[MAX+1][MAX+1][2];
int dx[4] = {-1,1,0,0} , dy[4] = {0,0,-1,1};

int bfs() {

    queue<pair<int,pair<int,int> > > q; // x,y,Pass

    q.push(make_pair(0,make_pair(0,1)));
    visited[0][0][1] = 1;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second.first;
        int P = q.front().second.second;
        q.pop();
        if(cx == N-1 && cy == M-1) {
            return visited[cx][cy][P];
        }
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M) {
                if(board[nx][ny] == 0 && visited[nx][ny][P] == 0) {
                    q.push(make_pair(nx,make_pair(ny,P)));
                    visited[nx][ny][P] = visited[cx][cy][P] + 1;
                }
                if(board[nx][ny] == 1 && P == 1) {
                    q.push(make_pair(nx,make_pair(ny,0)));
                    visited[nx][ny][0] = visited[cx][cy][P] + 1;
                }
            }
        
        }
    }
    return -1;
    
}

int main() {

    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d",&board[i][j]);
        }
    }
    memset(visited,0,sizeof(visited));
    printf("%d\n",bfs());
}