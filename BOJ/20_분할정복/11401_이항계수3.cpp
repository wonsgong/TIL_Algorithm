#include <cstdio>
#include <iostream>

#define MOD 1000000007LL
#define MAX 4000000

typedef long long ll;
using namespace std;


/* 페르마 소정리
    p가 소수, a가 정수 일때, a^p = a (mod p) 임. 
    -> a^(p-1) = 1 (mod p). 

    N! / K!(N-K)! = N!(K!(N-K)!)^-1 => 페르마 소정리 이용해서 (K!(N-K)!)^p-2 로 치환 후 풀이.
*/
ll fac[MAX+1];

ll pow(ll x, ll y) {   
    ll ret = 1;
    while (y > 0) {
        if (y % 2) {
            ret *= x;
            ret %= MOD;
        }
        x *= x;
        x %= MOD;
        y /= 2;
    }
    return ret;
}

int main() {

    int N,K;

    scanf("%d %d",&N,&K);

    if(N == 1 || K == 0) {
        printf("%d\n",1);
        return 0;
    }


    fac[1] = 1;
    for(int i=2; i<=N; i++) {
        fac[i] = (fac[i-1] * i) % MOD;
    }

    ll r = (fac[K] * fac[N-K]) % MOD;

    ll ans = pow(r,MOD-2);


    ans = (fac[N] * ans) % MOD;

    printf("%lld\n",ans);


    return 0;
}

