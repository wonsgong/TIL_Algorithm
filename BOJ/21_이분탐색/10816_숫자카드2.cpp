#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAXN 500000

using namespace std;

/* 
    upper_bound 와 lower_bound 를 빼주면 되는 거였다. -> 아주 괜찮네.
    map 사용해서 짜도 됨. 
*/

int n,m;
int N[MAXN+1], M[MAXN+1];

int bisrch(int num) {
    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(N[mid] <= num) lo = mid+1;
        else hi = mid-1;
    }
    int upper = lo;

    lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(N[mid] < num) lo = mid+1;
        else hi = mid-1;
    }
    int lower = lo;

    return upper - lower;
}

int main() {

    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",N+i);

    scanf("%d",&m);
    for(int i=0; i<m; i++) scanf("%d",M+i);

    sort(N,N+n);

    for(int i=0; i<m; i++) {
        printf("%d ",bisrch(M[i]));
    }
    printf("\n");

    return 0;
}
