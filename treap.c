#include <stdio.h>
#include <stdlib.h>

// Structure for a Treap Node
// We use pointers to left and right children, similar to a doubly linked list
struct Node {
    int key;
    int priority;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->priority = rand() % 100; // Random priority
    temp->left = temp->right = NULL;
    return temp;
}

// Right rotation to maintain heap property
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Return new root
    return x;
}

// Left rotation to maintain heap property
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Return new root
    return y;
}

// Function to search a key in the Treap
// Expected Time Complexity: O(log n)
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to insert a new key into the Treap
// Expected Time Complexity: O(log n)
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, return a new node
    if (!root)
        return newNode(key);

    // If key is smaller than root, insert in left subtree
    if (key <= root->key) {
        root->left = insert(root->left, key);

        // Fix Heap property if it is violated
        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    // If key is greater, insert in right subtree
    else {
        root->right = insert(root->right, key);

        // Fix Heap property if it is violated
        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}

// Function to delete a key from the Treap
// Expected Time Complexity: O(log n)
struct Node* deleteNode(struct Node* root, int key) {
    // Base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than root's key
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    // If the key to be deleted is greater than root's key
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    // If key is same as root's key, then this is the node to be deleted
    else {
        // If node has no left child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            root = temp;
        }
        // If node has no right child
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            root = temp;
        }
        // If node has both children
        else {
            // Find child with higher priority and rotate accordingly
            if (root->left->priority < root->right->priority) {
                root = leftRotate(root);
                root->left = deleteNode(root->left, key);
            }
            else {
                root = rightRotate(root);
                root->right = deleteNode(root->right, key);
            }
        }
    }
    return root;
}

// Utility function to print the tree in inorder
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("key: %d | priority: %d\n", root->key, root->priority);
        inorder(root->right);
    }
}

int main() {
    srand(100); // Seed for random number generation

    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the generated Treap:\n");
    inorder(root);

    printf("\nDeleting 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deletion:\n");
    inorder(root);

    printf("\nDeleting 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion:\n");
    inorder(root);

    printf("\nDeleting 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deletion:\n");
    inorder(root);

    struct Node* res = search(root, 50);
    if(res) {
        printf("\nFound key 50\n");
    } else {
        printf("\nKey 50 not found\n");
    }

    return 0;
}
