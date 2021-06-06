#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>  

/*
    토마토에 차원만 올린거라 배열을 하나만 추가해주면 됨.
*/

using namespace std;

int N,M,H;
int farm[101][101][101];
int dh[6] = {-1,1,0,0,0,0}, dx[6] = {0,0,-1,1,0,0}, dy[6] = {0,0,0,0,-1,1};
queue<pair<int,pair<int,int> > > q;

void bfs() {

    while(!q.empty()) {
        int ch = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        for(int i=0; i<6; i++) {
            int nh = ch + dh[i];
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(0 <= nh && nh < H && 0 <= nx && nx < N && 0 <= ny && ny < M && farm[nh][nx][ny] == 0) {
                q.push(make_pair(nh,make_pair(nx,ny)));
                farm[nh][nx][ny] = farm[ch][cx][cy] + 1;
            }
        }


    }


}

int main() {

    scanf("%d %d %d",&M,&N,&H);
    for(int h=0; h<H; h++) {
        for(int x=0; x<N; x++) {
            for(int y=0; y<M; y++){
                scanf("%d",&farm[h][x][y]);
                if(farm[h][x][y] == 1) q.push(make_pair(h,make_pair(x,y)));
            }
        }
    }

    bfs();

    int ans = 0;
    for(int h=0; h<H; h++) {
        for(int x=0; x<N; x++) {
            for(int y=0; y<M; y++){
                if(farm[h][x][y] == 0) {
                    printf("%d\n",-1);
                    return 0;
                }
                ans = max(ans,farm[h][x][y]);     
            }
        }
    }
    printf("%d\n",ans-1);



}