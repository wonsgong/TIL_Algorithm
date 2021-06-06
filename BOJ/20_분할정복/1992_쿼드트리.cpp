#include <cstdio>
#include <iostream>
#include <string> 
using namespace std;

int N;
string maps[65];
string ans;
void quadtree(int x, int y, int size) {

    char first = maps[x][y];
    bool flag = true;
    for(int i=x; i< x + size; i++) {
        for(int j=y; j < y + size; j++) {
            if(first != maps[i][j]) flag = false;
        }
    }
    if(flag) {
        if(first == '1') ans += '1';
        else ans += '0';
    }
    else {
        ans += '(';
        quadtree(x,y,size/2);
        quadtree(x,y+(size/2),size/2);
        quadtree(x+(size/2),y,size/2);
        quadtree(x+(size/2),y+(size/2),size/2);
        ans += ')';
    }
}

int main() {

    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        cin >> maps[i];
    }

    quadtree(0,0,N);


    cout << ans << endl;

    return 0;
}

