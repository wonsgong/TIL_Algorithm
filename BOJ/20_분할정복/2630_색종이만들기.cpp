#include <cstdio>
#include <iostream>
using namespace std;

int N,white,blue;
int maps[129][129];

void quadtree(int x, int y, int size) {

    int first = maps[x][y];
    bool flag = true;
    for(int i=x; i< x + size; i++) {
        for(int j=y; j < y + size; j++) {
            if(first != maps[i][j]) flag = false;
        }
    }
    if(flag) {
        if(first == 1) blue++;
        else white++;
    }
    else {
        quadtree(x,y,size/2);
        quadtree(x+(size/2),y,size/2);
        quadtree(x,y+(size/2),size/2);
        quadtree(x+(size/2),y+(size/2),size/2);
    }
}

int main() {

    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            scanf("%d",&maps[i][j]);
    }
    white = blue = 0;
    
    quadtree(0,0,N);


    printf("%d\n%d\n",white,blue);

    return 0;
}

