#include <stdio.h>
#include <stdlib.h>

// Defining structure of the Binary Tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create new node of the binary tree
node *createNode(int data) {
    node *newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory Allocation Failed");
        return NULL;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a new node in the binary tree
node* insert(node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    // Use a queue to perform level order insertion
    node** queue = (node**)malloc(100 * sizeof(node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        node* current = queue[front++];

        // Insert left child
        if (current->left == NULL) {
            current->left = createNode(data);
            break;
        } else {
            queue[rear++] = current->left;
        }

        // Insert right child
        if (current->right == NULL) {
            current->right = createNode(data);
            break;
        } else {
            queue[rear++] = current->right;
        }
    }

    free(queue);
    return root;
}

// Function for inorder traversal of the binary tree
void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);
    printf("%d ", root->data);     
    inorderTraversal(root->right);  
}


int main() {
    node* root = NULL;

    // Insert nodes into the binary tree
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    return 0;
}
