#include <cstdio>
#include <iostream>
using namespace std;

int N,a,b,c;
int maps[2188][2188];

void quadtree(int x, int y, int size) {

    int first = maps[x][y];
    bool flag = true;
    for(int i=x; i< x + size; i++) {
        for(int j=y; j < y + size; j++) {
            if(first != maps[i][j]) flag = false;
        }
    }
    if(flag) {
        if(first == -1) a++;
        else if(first == 0) b++;
        else c++;
    }
    else {
        int part = size/3;
        quadtree(x,y,part);
        quadtree(x,y+part,part);
        quadtree(x,y+(part*2),part);

        quadtree(x+part,y,part);
        quadtree(x+part,y+part,part);
        quadtree(x+part,y+(part*2),part);

        quadtree(x+(part*2),y,part);
        quadtree(x+(part*2),y+part,part);
        quadtree(x+(part*2),y+(part*2),part);
    }
}

int main() {

    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            scanf("%d",&maps[i][j]);
    }
    a = b = c = 0;
    
    quadtree(0,0,N);


    printf("%d\n%d\n%d\n",a,b,c);

    return 0;
}

