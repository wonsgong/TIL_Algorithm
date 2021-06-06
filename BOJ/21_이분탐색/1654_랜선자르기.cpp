#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

/*  parametric search
    이분탐색의 범위를 길이라고 생각하고 짜면 된다.
*/



int K,N;
vector<ll> lan;

ll bisrch(ll lo, ll hi) {

    while(lo <= hi) {

        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for(int i=0; i<K; i++) {
            cnt += (lan[i] / mid);
        }

        if(cnt < N) hi = mid-1;
        else lo = mid+1;
        
    }
    return lo - 1;
}


int main() {

    scanf("%d %d",&K,&N);
    ll tmp;
    ll top = 0;
    for(int i=0; i<K; i++) {
        scanf("%lld",&tmp);
        lan.push_back(tmp);
        top = max(top,tmp);
    }
    printf("%lld\n",bisrch(1,top));


    return 0;
}
