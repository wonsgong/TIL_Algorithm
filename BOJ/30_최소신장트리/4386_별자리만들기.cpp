#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define MAXN 100

using namespace std;

int N,par[MAXN+1];
float x,y;
vector<pair<float,pair<int,int> > > tree;
vector<pair<float,float> >stars;

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

float dist(pair<float,float> x, pair<float,float> y) {
    return sqrt(pow(x.first-y.first,2)+pow(x.second-y.second,2));
}

int main() {

    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        par[i] = i;
        scanf("%f %f",&x,&y);
        stars.push_back(make_pair(x,y));
    }
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            tree.push_back(make_pair(dist(stars[i],stars[j]),make_pair(i,j)));
        }
    }
    sort(tree.begin(),tree.end());
    float cost = 0;
    for(int i=0; i<tree.size(); i++) {
        float c = tree[i].first;
        int a = tree[i].second.first;
        int b = tree[i].second.second;
        if(find(a) == find(b)) continue;
        merge(a,b);
        cost += c;
    }
    printf("%.2f\n",cost);

    return 0;
}