//Program on Tree Traversals
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* NewNode(struct node *root, int data) {
    root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct node* Insertion(struct node *root, int data) {
    if(root == NULL) 
        root = NewNode(root, data);
        
    else if(data <= root->data)
        root->left = Insertion(root->left, data);
    
    else if(data > root->data) 
        root->right = Insertion(root->right, data);
        
    return root;
}

void Preorder(struct node *root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct node *root) {
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}
void Postorder(struct node *root) {
    if(root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node *root = NULL;
    root = Insertion(root,20);
    root = Insertion(root,30);
    root = Insertion(root,10);
    root = Insertion(root,15);
    root = Insertion(root,35);
    printf("Preorder:\n");
    Preorder(root);
    printf("\n");
    printf("Inorder:\n");
    Inorder(root);
    printf("\n");
    printf("Postorder:\n");
    Postorder(root);
    return 0;
}