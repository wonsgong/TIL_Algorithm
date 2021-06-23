#include <stdio.h>
#include <vector>
#include <string.h>

#define MAXN 100000
using namespace std;

int N,R,Q,x,y,cnt[MAXN+1];
vector<int> adjs[MAXN+1];
vector<int> child[MAXN+1];

void makeTree(int curNode, int par) {
    for(int i=0; i<adjs[curNode].size(); i++) {
        int node = adjs[curNode][i];
        if(node != par) {
            child[curNode].push_back(node);
            makeTree(node,curNode);
        }
    }
}

void cntSubtree(int curNode) {
    cnt[curNode] = 1;
    for(int i=0; i<child[curNode].size(); i++) {
        cntSubtree(child[curNode][i]);
        cnt[curNode] += cnt[child[curNode][i]];
    }
}


int main() {

    scanf("%d %d %d",&N,&R,&Q);
    for(int i=0; i<N-1; i++) {
        scanf("%d %d",&x,&y);
        adjs[x].push_back(y);
        adjs[y].push_back(x);
    }
    memset(cnt,0,sizeof(cnt));
    makeTree(R,-1);
    cntSubtree(R);

    for(int i=0; i<Q; i++) {
        scanf("%d",&x);
        printf("%d\n",cnt[x]);
    }

    return 0;
}