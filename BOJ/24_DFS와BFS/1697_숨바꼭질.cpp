#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>  
#include <string.h>
#define MAX 100000
using namespace std;

int main() {
    int N,M,board[MAX+1];
    scanf("%d %d",&N,&M);
    memset(board,0,sizeof(board));
    queue<int> q;

    board[N] = 1;
    q.push(N);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if (2*cur <= MAX && board[2*cur] == 0) { q.push(2*cur); board[2*cur] = board[cur]+1; }
        if (cur+1 <= MAX && board[cur+1] == 0) { q.push(cur+1); board[cur+1] = board[cur]+1; }
        if (0 <= cur-1 && cur-1 <= MAX && board[cur-1] == 0) { q.push(cur-1); board[cur-1] = board[cur]+1; }
    }

    printf("%d\n",board[M]-1);
}