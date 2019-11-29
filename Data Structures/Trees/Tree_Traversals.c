//Program on Tree Traversals
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* NewNode(struct Node *node, int data) {
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* Insertion(struct Node *node, int data) {
    if(node == NULL) 
        node = NewNode(node, data);
        
    else if(data <= node->data)
        node->left = Insertion(node->left, data);
    
    else if(data > node->data) 
        node->right = Insertion(node->right, data);
        
    return node;
}

void Preorder(struct Node *node) {
    if(node == NULL) return;
    printf("%d ", node->data);
    Preorder(node->left);
    Preorder(node->right);
}
void Inorder(struct Node *node) {
    if(node == NULL) return;
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}
void Postorder(struct Node *node) {
    if(node == NULL) return;
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->data);
}

int main() {
    struct Node *node = NULL;
    node = Insertion(node,20);
    node = Insertion(node,30);
    node = Insertion(node,10);
    node = Insertion(node,15);
    node = Insertion(node,35);
    printf("Preorder:\n");
    Preorder(node);
    printf("\n");
    printf("Inorder:\n");
    Inorder(node);
    printf("\n");
    printf("Postorder:\n");
    Postorder(node);
    return 0;
}