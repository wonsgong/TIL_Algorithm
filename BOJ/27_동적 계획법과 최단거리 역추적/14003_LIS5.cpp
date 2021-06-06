#include <cstdio>
#include <vector>

#define MAXN 1000000

using namespace std;

int nums[MAXN+1];
vector<int> lis,ans,idxs;

int N;

int bisrch(int n) {
    int left = 0, right = lis.size()-1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(lis[mid] < n) left = mid + 1;
        else right = mid - 1;
    }
    return right + 1;
}

int main() {

    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",nums+i);

    int cnt = 0;
    for(int i=0; i<N; i++) {

        if(lis.empty() || lis[cnt-1] < nums[i]) {
            lis.push_back(nums[i]);
            cnt++;
            idxs.push_back(lis.size()-1);
        }
        else {
            int idx = bisrch(nums[i]);
            lis[idx] = nums[i];
            idxs.push_back(idx);
        }
    }
    for(int i=idxs.size()-1; i>=0; i--) {
        if(idxs[i] == cnt-1) {
            ans.push_back(nums[i]);
            cnt--;
        }
    }
    printf("%lu\n",ans.size());
    for(int i=ans.size()-1; i>=0; i--) printf("%d ",ans[i]);
    return 0;
}