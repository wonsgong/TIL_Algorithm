#include <iostream>

#define MAXN 100000

using namespace std;
int inorder[MAXN+1],postorder[MAXN+1],inIdx[MAXN+1];
int N;

void preorder(int in_L, int in_R, int po_L, int po_R) {

    if((in_L > in_R) || (po_L > po_R)) return ;

    int root = postorder[po_R];
    int L = inIdx[root] - in_L;

    printf("%d ",root);
    preorder(in_L,in_L+L-1,po_L,po_L+L-1);
    preorder(in_L+L+1,in_R,po_L+L,po_R-1);

}

int main() {

    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",inorder+i);
    for(int i=0; i<N; i++) scanf("%d",postorder+i);
    for(int i=0; i<N; i++) inIdx[inorder[i]] = i;
    
    preorder(0,N-1,0,N-1);

    return 0;
}