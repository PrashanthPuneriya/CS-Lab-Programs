// Program on BST Operations
#include<stdio.h>
#include<stdlib.h>
int flag=0; // For Searching
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// New Node Creation
struct Node* NewNode(struct Node *node, int data) {
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insertion
struct Node* Insert(struct Node *node, int data) {
    if(node == NULL) 
        node = NewNode(node, data);
        
    else if(data <= node->data)
        node->left = Insert(node->left, data);
    
    else if(data > node->data) 
        node->right = Insert(node->right, data);

    return node;
}
// Searching
void Search(struct Node *node, int data) {
    if(node == NULL) return;
    if(node->data ==  data) flag = 1;
    else if(data < node->data) Search(node->left, data);
    else if(data > node->data) Search(node->right, data);
}
// Minimum Element of Right Subtree
struct Node* MinElement(struct Node *node) {
    while(node != NULL && node->left != NULL) 
        node = node->left;

    return node;
}
// Deletion
struct Node* Delete(struct Node *node, int data) {
    // Tree is Empty
    if(node == NULL) return node; 

    // Tree is Not Empty then traverse the Tree till you found the element to be deleted recursively
    if(data < node->data) node->left = Delete(node->left, data);

    else if(data > node->data) node->right = Delete(node->right, data);

    // If Element to be deleted is found
    else { 
        if(node->left == NULL) { // Replace with Right Node and
            struct Node *temp = node->right; 
            free(node);
            return temp;
        }
        else if(node->right == NULL) { // Replace with Left Node
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
        // Both Nodes are Present then, Replace the Node with the Min of the Right Subtree and delete that Min
            struct Node *temp = MinElement(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data); // Do the same Deletion process recursively to the min of the Right Subtree
    }
    return node;
}
// Inorder Traversal
void Inorder(struct Node *node) {
    if(node == NULL) return;
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}

int main() {
    struct Node *node = NULL;
    node = Insert(node,20);
    node = Insert(node,30);
    node = Insert(node,10);
    node = Insert(node,15);
    node = Insert(node,35);
    printf("Inorder:\n");
    Inorder(node);
    printf("\n");
    Search(node, 35);
    if(flag) printf("Found\n");
    else printf("Not Found\n");
    printf("After Delete:\n");
    node = Delete(node, 15);
    Inorder(node);
    return 0;
}

