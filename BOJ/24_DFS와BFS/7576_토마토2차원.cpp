#include <cstdio>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

/*
    그냥 다돌리면 시간 터짐 --> 미리 토마토 위치 queue 에 저장해서 진행하세요오오오오오
*/

int N,M;
int farm[1001][1001],dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
queue<pair<int,int> > q;

void bfs() {

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && farm[nx][ny] == 0) {
                q.push(make_pair(nx,ny));
                farm[nx][ny] = farm[cx][cy] + 1;
            }
        }
    }
}

int main() {

    scanf("%d %d",&M,&N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d",&farm[i][j]);
            if(farm[i][j] == 1) q.push(make_pair(i,j));
        }
    }
    bfs();

    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(farm[i][j] == 0) {
                printf("%d\n",-1);
                return 0;
            }
            ans = max(ans,farm[i][j]);
        }
    }
    printf("%d\n",ans-1);
}