#include <cstdio>
#include <iostream>
#include <vector>

/* leetcode 유사 문제.
int largestRectangleArea(vector<int>& h) {
            
    int n = h.size();
    
    if(n == 1) return h[0];
    vector<int> v(n,h[0]);
    if(v == h) return n*h[0];
    
    int ans = 0;
    for(int i=0; i<n; i++) {
        
        int cnt = 1;
        for(int j=i-1; j>=0; j--) {
            if(h[i] > h[j]) break;
            cnt++;
        }
        for(int j=i+1; j<n; j++) {
            if(h[i] > h[j]) break;
            cnt++;
        }
        
        ans = max(ans,h[i]*cnt);
    }
    
    return ans;
}
*/
/* 
    분할정복의 풀이과정은 어렵다. 
    처음엔 자신을 기준으로 양옆으로 나눠진 걸 생각했는데(leetcode처럼) 시간초과가 떠서 
    아에 싹 나누고 합치는 방식으로 생각. -> 리트코드에선 통과못하네ㅋ
*/
typedef long long ll;
using namespace std;

int N;
vector<ll> rec;

ll getArea(int left, int right) {

    if(left == right) return rec[left];

    int mid = (left + right) / 2;
    int low = mid, high = mid+1;
    ll ret = max(getArea(left,mid),getArea(mid+1,right));
    ll height = min(rec[mid],rec[mid+1]);
    ret = max(ret,height*2);

    while(left < low || high < right) {

        if(high < right && (left == low || rec[low-1] < rec[high+1])) {
            high++;
            height = min(height,rec[high]);
        }
        else {
            low--;
            height = min(height,rec[low]);
        }
        ret = max(ret,height * (high-low+1));
    }
    return ret;
}


int main() {

    while(true) {

        scanf("%d",&N);
        if(N == 0) break;

        rec.clear();
        for(int i=0; i<N; i++) {
            ll tmp;
            scanf("%lld",&tmp);
            rec.push_back(tmp);
        }
        
        
        printf("%lld\n",getArea(0,N-1));

    }

    return 0;
}
