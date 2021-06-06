#include <iostream>
#include <vector>

#define MAXN 100
#define INF 987654321

using namespace std;

vector<int> path[MAXN+1][MAXN+1];
int adjs[MAXN+1][MAXN+1];
int N,M,x,y,c;

void getPath(int i, int j, vector<int>& K) {
    int k = path[i][j][path[i][j].size()-1];

    if(path[i][k].size() != 0) getPath(i,k,K);
    K.push_back(k);
    if(path[k][j].size() != 0) getPath(k,j,K);

}

void floyd() {
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(adjs[i][j] > adjs[i][k] + adjs[k][j]){
                    adjs[i][j] = adjs[i][k] + adjs[k][j];
                    path[i][j].push_back(k);
                }
            }
        }
    }
}

int main() {

    for(int i=0; i<=MAXN; i++) {
        for(int j=0; j<=MAXN; j++){
            adjs[i][j] = INF;
        }
    }
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> x >> y >> c;
        if(adjs[x][y] > c) adjs[x][y] = c;
    }
    floyd();

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j || adjs[i][j] == INF) cout << 0 << " ";
            else cout << adjs[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j || adjs[i][j] == INF) cout << 0 << endl;
            else if(path[i][j].size() == 0) cout << 2 << " " << i << " " << j << endl;
            else {
                vector<int> K;
                K.push_back(i);
                getPath(i,j,K);
                K.push_back(j);
                cout << K.size();
                for(int i=0; i<K.size(); i++) cout << " " << K[i];
                cout << "\n";
            }
        }
    }
    return 0;
}