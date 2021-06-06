#include <cstdio>
#include <vector>

#define MAXN 1000

using namespace std;
int nums[MAXN+1], dp[MAXN+1];
vector<int> lis[MAXN+1];
vector<int> ans;
int N;
int main() {

    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",nums+i);

    for(int i=0; i<N; i++) {
        dp[i] = 1;
        lis[i].push_back(nums[i]);
        for(int j=0; j<i; j++){
            if(nums[i] > nums[j]) {
                if(dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    lis[i].clear();
                    lis[i] = lis[j];
                    lis[i].push_back(nums[i]);
                }
            }
        }
        ans = ans.size() < lis[i].size() ? lis[i] : ans;
    }
    printf("%lu\n",ans.size());
    for(int i=0; i<ans.size(); i++) printf("%d ",ans[i]);

    return 0;
}