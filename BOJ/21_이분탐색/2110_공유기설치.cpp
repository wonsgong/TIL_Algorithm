#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

/*
    다시 풀어봐야 할 문제.
    mid 기준으로 left <= right 가 됨. 즉, 공유기 수가 원하는 수 만큼되면 right 부분에서 체크하는것.
*/


int N,C;
vector<ll> home;

ll bisrch(int lo, int hi) {

    while(lo <= hi) {
        ll mid = (lo + hi) / 2;

        int prev = home[0];
        int cnt = 1;

        for(int i=1; i<N; i++) {
            if(home[i] - prev >= mid) {
                cnt++;
                prev = home[i];
            }
        }
        if(cnt >= C) lo = mid + 1;
        else hi = mid - 1;
    }

    return lo - 1;
}


int main() {

    scanf("%d %d",&N,&C);
    ll tmp;
    for(int i=0; i<N; i++) {
        scanf("%lld",&tmp);
        home.push_back(tmp);
    }

    sort(home.begin(),home.end());

    printf("%lld\n",bisrch(1,home[N-1] - home[0]));


    return 0;
}
