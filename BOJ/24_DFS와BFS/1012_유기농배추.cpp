#include <cstdio>
#include <iostream>
#include <string.h>

#define MAX 50
using namespace std;

int T,N,M,K,x,y;
int board[MAX+1][MAX+1];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
bool visited[MAX+1][MAX+1];

void dfs(int x, int y) {
    visited[x][y] = true;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)  continue;
        if (board[nx][ny] == 1 && visited[nx][ny] == false) {
            dfs(nx,ny);
        }
    }
}

int main() {

    scanf("%d",&T);
    for(int i=0; i<T; i++) {
        memset(board,0,sizeof(board));
        memset(visited,false,sizeof(visited));
        scanf("%d %d %d",&M,&N,&K);
        for(int i=0; i<K; i++) {
            scanf("%d %d",&x,&y);
            board[y][x] = 1;    
        }
        int ans = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(board[i][j] == 1 && visited[i][j] == false){
                    ans += 1;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }



    return 0;
}