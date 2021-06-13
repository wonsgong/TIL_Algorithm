#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#define MAXN 1000

using namespace std;

int N,M,a,b,par[MAXN+1];
double x,y;
vector<pair<double,pair<int,int> > > tree;
vector<pair<double,double> > space;

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

double dist(pair<double,double> x, pair<double,double> y) {
    return sqrt(pow(x.first-y.first,2)+pow(x.second-y.second,2));
}

int main() {

    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        par[i] = i;
        scanf("%lf %lf",&x,&y);
        space.push_back(make_pair(x,y));
    }
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            tree.push_back(make_pair(dist(space[i],space[j]),make_pair(i+1,j+1)));
        }
    }
    for(int i=0; i<M; i++) {
        scanf("%d %d",&a,&b);
        merge(a,b);
    }

    sort(tree.begin(),tree.end());
    double cost = 0;
    for(int i=0; i<tree.size(); i++) {
        double c = tree[i].first;
        int a = tree[i].second.first;
        int b = tree[i].second.second;
        if(find(a) == find(b)) continue;
        merge(a,b);
        cost += c;
    }
    printf("%.2lf\n",cost);

    return 0;
}