#include <iostream>
#include <vector>

#define MAXN 10000

using namespace std;

vector<pair<int,pair<int,int> > >tree;
int par[MAXN+1];
int V,E,a,b,c;
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

int main() {
    
    scanf("%d %d",&V,&E);
    for(int i=0; i<E; i++) {
        scanf("%d %d %d",&a,&b,&c);
        tree.push_back(make_pair(c,make_pair(a,b)));
    }
    for(int i=0; i<=V; i++) par[i] = i;
    
    sort(tree.begin(),tree.end());
    int cost = 0;
    for(int i=0; i<E; i++) {
        int c = tree[i].first;
        int a = tree[i].second.first;
        int b = tree[i].second.second;

        if(find(a) == find(b)) continue;
        merge(a,b);
        cost += c;
    }
    printf("%d\n",cost);
    return 0;
}