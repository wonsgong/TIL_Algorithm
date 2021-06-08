#include <iostream>

using namespace std;

int N;
char tree[26][2];

void preorder(char node) {
    printf("%c",node);
    if(tree[node-'A'][0] != '.') preorder(tree[node-'A'][0]);
    if(tree[node-'A'][1] != '.') preorder(tree[node-'A'][1]);
}
void inorder(char node) {
    if(tree[node-'A'][0] != '.') inorder(tree[node-'A'][0]);
    printf("%c",node);
    if(tree[node-'A'][1] != '.') inorder(tree[node-'A'][1]);
}
void postorder(char node) {
    if(tree[node-'A'][0] != '.') postorder(tree[node-'A'][0]);
    if(tree[node-'A'][1] != '.') postorder(tree[node-'A'][1]);
    printf("%c",node);
}

int main() {
    char root,left,right;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> root >> left >> right;
        tree[root-'A'][0] = left;
        tree[root-'A'][1] = right;
    }
    preorder('A'); printf("\n");
    inorder('A'); printf("\n");
    postorder('A'); printf("\n");
    return 0;
}