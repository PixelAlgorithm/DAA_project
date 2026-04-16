#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreapNode {
  int key, priority;
  struct TreapNode *left, *right;
} TreapNode;

TreapNode *newNode(int key) {
  TreapNode *node = (TreapNode *)malloc(sizeof(TreapNode));
  if (!node) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(0);
  }
  node->key = key;
  node->priority = rand() % 100;
  node->left = NULL;
  node->right = NULL;
  return node;
}

TreapNode *rightRotate(TreapNode *y) {
  TreapNode *x = y->left;
  TreapNode *T2 = x->right;

  x->right = y;
  y->left = T2;

  return x; /* new root */

TreapNode *leftRotate(TreapNode *x) {
  TreapNode *y = x->right;
  TreapNode *T2 = y->left;

  y->left = x;
  x->right = T2;

  return y;
}

TreapNode *search(TreapNode *root, int key) {
  if (root == NULL || root->key == key)
    return root;

  if (key > root->key)
    return search(root->right, key);

  return search(root->left, key);
}

TreapNode *insert(TreapNode *root, int key) {
  if (root == NULL)
    return newNode(key);

  if (key <= root->key) {
    root->left = insert(root->left, key);

    if (root->left->priority > root->priority)
      root = rightRotate(root);
  } else {
    root->right = insert(root->right, key);

    if (root->right->priority > root->priority)
      root = leftRotate(root);
  }

  return root;
}


TreapNode *deleteNode(TreapNode *root, int key) {
  if (root == NULL)
    return NULL;

  if (key < root->key) {
    root->left = deleteNode(root->left, key);
    return root;
  }
  if (key > root->key) {
    root->right = deleteNode(root->right, key);
    return root;
  }

  if (root->left == NULL) {
    TreapNode *temp = root->right;
    free(root);
    return temp;
  }

  if (root->right == NULL) {
    TreapNode *temp = root->left;
    free(root);
    return temp;
  }

  if (root->right->priority > root->left->priority) {
    root = leftRotate(root);
    root->left = deleteNode(root->left, key);
  } else {
    root = rightRotate(root);
    root->right = deleteNode(root->right, key);
  }

  return root;
}


void inorder(TreapNode *root) {
  if (root == NULL)
    return;

  inorder(root->left);

  printf("key: %2d | priority: %2d", root->key, root->priority);
  if (root->left)
    printf(" | left: %d", root->left->key);
  if (root->right)
    printf(" | right: %d", root->right->key);
  printf("\n");

  inorder(root->right);
}


void freeTree(TreapNode *root) {
  if (root == NULL)
    return;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}


void printMenu(void) {
  printf("\n╔══════════════════════════╗\n");
  printf("║        TREAP MENU        ║\n");
  printf("╠══════════════════════════╣\n");
  printf("║  1. Insert               ║\n");
  printf("║  2. Delete               ║\n");
  printf("║  3. Search               ║\n");
  printf("║  4. Inorder Traversal    ║\n");
  printf("║  5. Clear Tree           ║\n");
  printf("║  0. Exit                 ║\n");
  printf("╚══════════════════════════╝\n");
  printf("Choice: ");
}

int main(void) {
  srand((unsigned)time(NULL));

  TreapNode *root = NULL;
  int choice, key;

  printf("=== Treap — Interactive Demo ===\n");

  do {
    printMenu();

    if (scanf("%d", &choice) != 1) {
      /* flush bad input */
      while (getchar() != '\n')
        ;
      choice = -1;
    }

    switch (choice) {

    case 1:
      printf("Enter key to insert: ");
      scanf("%d", &key);
      root = insert(root, key);
      printf("Inserted %d into the treap.\n", key);
      break;

    case 2:
      if (root == NULL) {
        printf("Tree is empty. Nothing to delete.\n");
        break;
      }
      printf("Enter key to delete: ");
      scanf("%d", &key);
      if (search(root, key)) {
        root = deleteNode(root, key);
        printf("Deleted %d from the treap.\n", key);
      } else {
        printf("Key %d not found in the treap.\n", key);
      }
      break;

    case 3:
      if (root == NULL) {
        printf("Tree is empty.\n");
        break;
      }
      printf("Enter key to search: ");
      scanf("%d", &key);
      printf("Search(%d): %s\n", key,
             search(root, key) ? "Found ✓" : "Not Found ✗");
      break;

    case 4:
      if (root == NULL) {
        printf("Tree is empty.\n");
      } else {
        printf("\n--- Inorder Traversal ---\n");
        inorder(root);
      }
      break;

    case 5:
      freeTree(root);
      root = NULL;
      printf("Tree cleared.\n");
      break;

    case 0:
      printf("Exiting. Freeing memory...\n");
      freeTree(root);
      break;

    default:
      printf("Invalid choice. Please enter 0-5.\n");
      break;
    }

  } while (choice != 0);

  return 0;
}