#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/*
    B의 범위가 int 가 아니라는 사실을 간과했다. 범위 파악 잘해서 타입을 잘 적자.
    Mat 구조체 만들어줘서 풀어도 댐 like struct Mat (int m[6][6]);
*/


typedef vector<vector<int> > vv;
int N;
long long B;

vv Iden(int n) {
    vv I(n,vector<int>(n,0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if(i==j) I[i][j] = 1;
        }
    }
    return I;    
}

vv multi(vv A, vv B) {
    vv ret(N,vector<int>(N,0));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int tmp = 0;
            for(int k=0; k<N; k++) {
                tmp += (A[i][k] * B[k][j]) % 1000;
            }
            ret[i][j] = tmp % 1000;
        }
    }
    return ret;
}

vv pow(vv a, long long B) {

    if(B == 0) return Iden(N);
    if(B % 2) return multi(pow(a,B-1),a);

    vv half = pow(a,B/2);

    return multi(half,half);

}


int main() {

    scanf("%d %lld",&N,&B);    

    vv A(N,vector<int>(N,0));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            scanf("%d",&A[i][j]);
    }


    vv ans = pow(A,B);


    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }



    return 0;
}
