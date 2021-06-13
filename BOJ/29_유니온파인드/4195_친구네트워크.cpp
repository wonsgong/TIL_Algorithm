#include <iostream>
#include <string>
#include <map>

#define MAXF 200000

using namespace std;

int T,F;
char tmp[21];
string x,y;
pair<int, int> par[MAXF+1];


int find(int x) {
    if(par[x].first == x) return par[x].first;
    else return par[x].first = find(par[x].first);
}

void merge(int x, int y) {
    int p_x = find(x);
    int p_y = find(y);
    if(p_x == p_y) return ;

    par[p_x].first = p_y;
    par[p_y].second += par[p_x].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> F;
        int cnt = 1;
        map<string,int> names;
        while(F--) {
            cin >> x >> y;
            if(names.find(x) == names.end()) {
                names[x] = cnt++;
                par[names[x]] = make_pair(names[x],1);
            }
            if(names.find(y) == names.end()) { 
                names[y] = cnt++;
                par[names[y]] = make_pair(names[y],1);
            }
            merge(names[x],names[y]);

            cout << par[find(names[y])].second << "\n";
        }
    }


}
