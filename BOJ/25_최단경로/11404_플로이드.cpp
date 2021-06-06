#include <cstdio>
#include <iostream>
#include <vector>

#define MAX 100
#define INF 987654321
using namespace std;

int N,M;
int adjs[MAX+1][MAX+1];

void floyd() {
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i == j) continue; 
                if(adjs[i][j] > adjs[i][k] + adjs[k][j])
                    adjs[i][j] = adjs[i][k] + adjs[k][j];
            }
        }
    }
}

int main() {
   
    int x,y,c;
    scanf("%d",&N);
    scanf("%d",&M);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++){
            adjs[i][j] = INF;
        }
    }

    for(int i=0; i<M; i++) {
        scanf("%d %d %d",&x,&y,&c);
        if(adjs[x][y] > c) adjs[x][y] = c;
    }
    floyd();

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(adjs[i][j] == INF) printf("0 ");
            else printf("%d ",adjs[i][j]);
        }
        printf("\n");
    }



    return 0;
}