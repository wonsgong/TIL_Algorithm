#include <cstdio>
#include <iostream>

using namespace std;

/* 
    N 의 범위가 [1,100] 이기 때문에 O(N^3) 으로 풀어도 무방. 
    간단하게 행렬 곱셉을 구현해주면 되는 문제.
*/

int N,M,K;
int matA[101][101], matB[101][101], ans[101][101];

int main() {

    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            scanf("%d",&matA[i][j]);
        }
    }
    scanf("%d %d",&M,&K);
    for(int i=0; i<M; i++) {
        for(int j=0; j<K; j++){
            scanf("%d",&matB[i][j]);
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<K; j++) {
            int tmp = 0;
            for(int k=0; k<M; k++) {
                tmp += (matA[i][k] * matB[k][j]);
            }
            ans[i][j] = tmp;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }



    return 0;
}

