#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void traverse(Node* root, int type) {
    if (!root) return;
    if (type == 1) traverse(root->left, type);
    if (type != 3) printf("%d ", root->data);
    traverse(root->right, type);
    if (type == 3) printf("%d ", root->data);
}

Node* search(Node* root, int key) {
    while (root && root->data != key)
        root = key < root->data ? root->left : root->right;
    return root;
}

int main() {
    Node* root = NULL;
    int n, data, opt;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("1) Inorder\n2) Preorder\n3) Postorder\n4) Search\nChoose option: ");
    scanf("%d", &opt);
    if (opt >= 1 && opt <= 3) traverse(root, opt), printf("\n");
    else if (opt == 4) {
        printf("Enter element to search: ");
        scanf("%d", &data);
        printf("%s\n", search(root, data) ? "Element found" : "Element not found");
    } else printf("Invalid option\n");
    
    return 0;
}
