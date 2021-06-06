#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int N,M;
vector<ll> tree;

ll bisrch(ll lo, ll hi) {

    while(lo <= hi) {

        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for(int i=0; i<N; i++) {
            cnt += (tree[i] - mid) > 0 ? tree[i] - mid : 0;
        }

        if(cnt < M) hi = mid-1;
        else lo = mid+1;
        
    }
    return lo - 1;
}


int main() {

    scanf("%d %d",&N,&M);

    ll tmp;
    ll top = 0;
    for(int i=0; i<N; i++) {
        scanf("%lld",&tmp);
        tree.push_back(tmp);
        top = max(top,tmp);
    }

    printf("%lld\n",bisrch(1,top));

    return 0;
}
