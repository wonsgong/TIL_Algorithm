#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* node, int val) {
    if(node == NULL) {
        node = new Node();
        node -> data = val;
        node -> left = node -> right = NULL;
    }
    else if(node->data < val) {
        node->right = insert(node->right,val);
    }
    else node->left = insert(node->left,val);
    
    return node;
}
void postorder(Node* node) {
    if(node->left != NULL) postorder(node->left);
    if(node->right != NULL) postorder(node->right);

    printf("%d\n",node->data);
}

int main() {

    int x;
    Node* root = NULL;
    while (scanf("%d",&x) != EOF){
        root = insert(root,x);
    }
    postorder(root);
}


