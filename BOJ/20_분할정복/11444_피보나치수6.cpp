#include <cstdio>
#include <iostream>
#include <vector>

#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > vv;

/*
    피보나치의 점화식을 행렬식으로 표현할 줄 알면 쉽게 풀리는 문제다.(떠올리기가 어렵지...)
    Fn = Fn-1 + Fn-2 
    => [Fn+1 Fn][Fn Fn-1] = [1 1][1 0]^n 
    즉 행렬 제곱 문제로 바뀌게 된다.
*/

vv Iden() {
    vv I(2,vector<ll>(2,0));
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            if(i==j) I[i][j] = 1;
        }
    }
    return I;
}
vv multi(vv A, vv B) {

    vv ans(2,vector<ll>(2,0));

    for(int i=0; i<2; i++) {

        for(int j=0; j<2; j++) {
            ll tmp = 0;
            for(int k=0; k<2; k++) {
                tmp += (A[i][k] * B[k][j]) % MOD;
            }
            ans[i][j] = tmp % MOD;
        }
    }
    return ans;
}

vv pow(vv A, ll N){

    if(N == 0) return Iden();
    if(N % 2) return multi(pow(A,N-1),A);

    vv half = pow(A,N/2);

    return multi(half,half);
}


int main() {

    ll N;
    scanf("%lld",&N);

    vv A(2,vector<ll>(2,1));
    A[1][1] = 0;


    vv ans = pow(A,N);

    printf("%lld\n",ans[0][1]);

    return 0;
}
