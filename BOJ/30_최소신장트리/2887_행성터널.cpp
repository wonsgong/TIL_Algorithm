#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100000

using namespace std;

int N,x,y,z,par[MAXN+1];
vector<pair<int,pair<int,int> > > tree;
vector<pair<pair<int,int>,pair<int,int> > > stars;

int find(int x) {
    if(par[x] == x) return par[x];
    else return par[x] = find(par[x]);
}

void merge(int x, int y) {
    int p_x = find(x);
    int p_y = find(y);
    if(p_x == p_y) return ;
    par[p_x] = p_y;    
}
bool cmp1(pair<pair<int,int>,pair<int,int> > a, pair<pair<int,int>,pair<int,int> > b) {
    return a.first.first < b.first.first;
}
bool cmp2(pair<pair<int,int>,pair<int,int> > a, pair<pair<int,int>,pair<int,int> > b) {
    return a.first.second < b.first.second;
}
bool cmp3(pair<pair<int,int>,pair<int,int> > a, pair<pair<int,int>,pair<int,int> > b) {
    return a.second.first < b.second.first;
}


int main() {

    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        par[i] = i;
        scanf("%d %d %d",&x,&y,&z);
        stars.push_back(make_pair(make_pair(x,y),make_pair(z,i)));
    }
    for(int i=0; i<3; i++) {
        int cost;
        if(i==0) {
            sort(stars.begin(),stars.end(),cmp1);
            for(int j=1; j<N; j++) {
                cost = abs(stars[j-1].first.first - stars[j].first.first);
                tree.push_back(make_pair(cost,make_pair(stars[j-1].second.second,stars[j].second.second)));
            }
        }
        else if(i==1) {
            sort(stars.begin(),stars.end(),cmp2);
            for(int j=1; j<N; j++) {
                cost = abs(stars[j-1].first.second - stars[j].first.second);
                tree.push_back(make_pair(cost,make_pair(stars[j-1].second.second,stars[j].second.second)));
            }
        }
        else {
            sort(stars.begin(),stars.end(),cmp3);
            for(int j=1; j<N; j++) {
                cost = abs(stars[j-1].second.first - stars[j].second.first);
                tree.push_back(make_pair(cost,make_pair(stars[j-1].second.second,stars[j].second.second)));
            }
        }
    }
    sort(tree.begin(),tree.end());
    int cost = 0;
    for(int i=0; i<tree.size(); i++) {
        int c = tree[i].first;
        int x = tree[i].second.first;
        int y = tree[i].second.second;
        if(find(x) == find(y)) continue;

        merge(x,y);
        cost += c;
    }
    printf("%d\n",cost);

    return 0;
}