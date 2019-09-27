// Program on BST Operations
#include<stdio.h>
#include<stdlib.h>
int flag=0; // For Searching
struct node {
    int element;
    struct node *left;
    struct node *right;
};

// New Node Creation
struct node* NewNode(struct node *root, int element) {
    root = (struct node*)malloc(sizeof(struct node));
    root->element = element;
    root->left = NULL;
    root->right = NULL;
    return root;
}

// Insertion
struct node* Insert(struct node *root, int element) {
    if(root == NULL) 
        root = NewNode(root, element);
        
    else if(element <= root->element)
        root->left = Insert(root->left, element);
    
    else if(element > root->element) 
        root->right = Insert(root->right, element);

    return root;
}
// Searching
void Search(struct node *root, int element) {
    if(root == NULL) return;
    if(root->element ==  element) flag = 1;
    else if(element < root->element) Search(root->left, element);
    else if(element > root->element) Search(root->right, element);
}
// Minimum Element of Right Subtree
struct node* MinElement(struct node *root) {
    while(root != NULL && root->left != NULL) 
        root = root->left;

    return root;
}
// Deletion
struct node* Delete(struct node *root, int element) {
    // Tree is Empty
    if(root == NULL) return root; 

    // Tree is Not Empty then traverse the Tree till you found the element to be deleted recursively
    if(element < root->element) root->left = Delete(root->left, element);

    else if(element > root->element) root->right = Delete(root->right, element);

    // If element is found
    else { 
        // If it doesn't consists any child nodes then, the first if statement returns NULL to its caller
        if(root->left == NULL) { // Replace with Right Node and
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) { // Replace with Left Node
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Both Nodes are Present then, Replace with Min of the Right Subtree
            struct node *temp = MinElement(root->right);
            root->element = temp->element;
            root->right = Delete(root->right, temp->element); // Do the same Deletion process recursively to the min of the Right Subtree
    }
    return root;
}
// Inorder Traversal
void Inorder(struct node *root) {
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ", root->element);
    Inorder(root->right);
}

int main() {
    struct node *root = NULL;
    root = Insert(root,20);
    root = Insert(root,30);
    root = Insert(root,10);
    root = Insert(root,15);
    root = Insert(root,35);
    printf("Inorder:\n");
    Inorder(root);
    printf("\n");
    Search(root, 35);
    if(flag) printf("Found\n");
    else printf("Not Found\n");
    printf("After Delete:\n");
    root = Delete(root, 15);
    Inorder(root);
    return 0;
}

