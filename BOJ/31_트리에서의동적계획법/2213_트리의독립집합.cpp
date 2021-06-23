#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 100000
using namespace std;

int N,x,y,dist[MAXN+1][2],weight[MAXN+1];
vector<int> adjs[MAXN+1];
vector<int> res;

void makeTree(int curNode, int par) {
    for(int i=0; i<adjs[curNode].size(); i++) {
        int node = adjs[curNode][i];
        if(node != par) {
            makeTree(node,curNode);
        }
    }
    dist[curNode][0] = 0;
    dist[curNode][1] = weight[curNode];

    for(int i=0; i<adjs[curNode].size(); i++) {
        int node = adjs[curNode][i];
        if(node != par) {
            dist[curNode][0] += max(dist[node][0],dist[node][1]);
            dist[curNode][1] += dist[node][0];
        }
    }
    
}

void trace(int curNode, int isInclude, int par) {
    if(isInclude) {
        res.push_back(curNode);
        for(int i=0; i<adjs[curNode].size(); i++) {
            int node = adjs[curNode][i];
            if(node != par) {
                trace(node,0,curNode);
            }
        }
    }
    else {
        for(int i=0; i<adjs[curNode].size(); i++) {
            int node = adjs[curNode][i];
            if(node != par) {
                if(dist[node][0] < dist[node][1])
                    trace(node,1,curNode);
                else 
                    trace(node,0,curNode);
            }
        }
    }
}


int main() {

    scanf("%d",&N);
    for(int i=1; i<=N; i++) scanf("%d",weight+i);
    for(int i=0; i<N-1; i++) {
        scanf("%d %d",&x,&y);
        adjs[x].push_back(y);
        adjs[y].push_back(x);
    }
    makeTree(1,0);

    printf("%d\n",max(dist[1][0],dist[1][1]));
    if(dist[1][0] < dist[1][1]) trace(1,1,0);
    else trace(1,0,0);

    sort(res.begin(),res.end());
    for(int i=0; i<res.size(); i++){
        printf("%d ",res[i]);
    }

    return 0;
}