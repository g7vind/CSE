

//Tree operations

#include<stdio.h>
#include<stdlib.h>

//Structure for tree
struct node{
    int data;
    struct node* left;
    struct node* right;
};

//Function to create a new node
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Function to insert a node
struct node* insert(struct node* node, int data){
    if(node == NULL){
        return newNode(data);
    }
    else{
        if(data<= node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;
    }
}

//Function to find the minimum value in the tree
int minValue(struct node* node){
    struct node* current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}

//Function to find the maximum value in the tree
int maxValue(struct node* node){
    struct node* current = node;
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}

//Function to find the height of the tree
int height(struct node* node){
    if(node == NULL){
        return 0;
    }
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);
        if(lheight > rheight){
            return lheight + 1;
        }
        else{
            return rheight + 1;
        }
    }
}

//Function to find the size of the tree
int size(struct node* node){
    if(node == NULL){
        return 0;
    }
    else{
        return (size(node->left) + 1 + size(node->right));
    }
}

//Function to find the number of leaves in the tree
int leaves(struct node* node){
    if(node == NULL){
        return 0;
    }
    if(node->left == NULL && node->right == NULL){
        return 1;
    }
    else{
        return (leaves(node->left) + leaves(node->right));
    }
}

//Function to delete a node
struct node* deleteNode(struct node* node, int data){
    if(node == NULL){
        return node;
    }
    else if(data < node->data){
        node->left = deleteNode(node->left, data);
    }
    else if(data > node->data){
        node->right = deleteNode(node->right, data);
    }
    else{
        //Node with no children
        if(node->left == NULL && node->right == NULL){
            free(node);
            node = NULL;
        }
        //Node with one child
        else if(node->left == NULL){
            struct node* temp = node;
            node = node->right;
            free(temp);
        }
        else if(node->right == NULL){
            struct node* temp = node;
            node = node->left;
            free(temp);
        }
        //Node with two children
        else{
            int min = minValue(node->right);
            node->data = min;
            node->right = deleteNode(node->right, min);
        }
    }
    return node;
}

//Function to perform preorder traversal
void preOrder(struct node* node){
    if(node == NULL){
        return;
    }
    else{
        printf("%d\t", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

//Function to perform inorder traversal
void inOrder(struct node* node){
    if(node == NULL){
        return;
    }
    else{
        inOrder(node->left);
        printf("%d\t", node->data);
        inOrder(node->right);
    }
}

//Function to perform postorder traversal
void postOrder(struct node* node){
    if(node == NULL){
        return;
    }
    else{
        postOrder(node->left);
        postOrder(node->right);
        printf("%d\t", node->data);
    }
}

//Main function
int main(){
    struct node* root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 30);
    printf("Minimum value in the tree: %d\n", minValue(root));
    printf("Maximum value in the tree: %d\n", maxValue(root));
    printf("Height of the tree: %d\n", height(root));
    printf("Size of the tree: %d\n", size(root));
    printf("Number of leaves in the tree: %d\n", leaves(root));
    printf("Preorder traversal of the tree: ");
    preOrder(root);
    printf("\nInorder traversal of the tree: ");
    inOrder(root);
    printf("\nPostorder traversal of the tree: ");
    postOrder(root);
    printf("\nAfter deleting node 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the tree: ");
    inOrder(root);
    printf("\n");
    return 0;
}