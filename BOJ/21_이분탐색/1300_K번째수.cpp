#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

/*
    mid 값 보다 작은 수 가 몇개인지 알아내는 게 중요
    i * j < mid => i 번째 row 에 j 가 중요. j < mid / i. 
*/

int main() {

    ll N,K;
    scanf("%lld %lld",&N,&K);

    ll lo = 1, hi = K;

    while(lo <= hi) {

        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for(int i=1; i<=N; i++) {
            cnt += min(mid/i,N);
        }
        if(cnt < K) lo = mid + 1; 
        else hi = mid - 1;
        
    }
    printf("%lld\n",hi + 1);

    return 0;
}
