#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>  
#include <string.h>

#define MAX 300
using namespace std;

int T,I,kx,ky,tx,ty;
int board[MAX+1][MAX+1];
int dx[8] = {-2,-1,1,2,2,1,-1,-2} , dy[8] = {1,2,2,1,-1,-2,-2,-1};

int bfs() {
    
    queue<pair<int,int> > q;
    q.push(make_pair(kx,ky));
    board[kx][ky] = 1;
    int ans = 987654321;
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second; 
        q.pop();
        if(cx == tx && cy == ty && board[cx][cy] != 0){
            ans = min(ans,board[cx][cy]);
        } 
        for(int i=0; i<8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0<= nx && nx < I && 0 <= ny && ny < I && board[nx][ny] == 0){
                q.push(make_pair(nx,ny));
                board[nx][ny] = board[cx][cy] + 1;
            }
        }
    }
    return ans-1;
}

int main() {

    scanf("%d",&T);
    for(int i=0; i<T; i++) {
        scanf("%d",&I);
        scanf("%d %d",&kx,&ky);
        scanf("%d %d",&tx,&ty);
        memset(board,0,sizeof(board));
        if(kx == tx && ky == ty){
            printf("%d\n",0);
        }
        else{ 
            printf("%d\n",bfs());
        }
    }
}