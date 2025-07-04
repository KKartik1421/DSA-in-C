#include <stdio.h>
#include <stdlib.h>

void options() {
    printf("1) Inorder traversal of the BST\n");
    printf("2) Preorder traversal of the BST\n");
    printf("3) Postorder traversal of the BST\n");
    printf("4) Search the element\n");
    printf("5) Delete an element\n");
    printf("6) Exit\n");
}

struct node {
    int data;
    struct node *right;
    struct node *left;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
} 

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct node* searchNode(struct node* root, int key) {
    struct node* temp = root;
    int flag = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            flag = 1;
            break;
        } else if (key < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    return flag == 1 ? temp : NULL; // Return the found node or NULL
}

struct node* findMin(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    // Find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = findMin(root->right);
        root->data = temp->data; // Copy the inorder successor's data to this node
        root->right = deleteNode(root->right, temp->data); 
    }
    return root;
}

int main() {
    struct node* root = NULL;
    int n, data, opt;

    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    while (1) {
        options();
        scanf("%d", &opt);

        if (opt == 1) {
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
        } else if (opt == 2) {
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
        } else if (opt == 3) {
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
        } else if (opt == 4) {
            printf("Enter the element to search: ");
            scanf("%d", &data);
            struct node* result = searchNode(root, data);
            if (result != NULL) {
                printf("Element %d found in the BST.\n", result->data);
            } else {
                printf("Element %d not found in the BST.\n", data);
            }
        } else if (opt == 5) {
            printf("Enter the element to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            printf("Element %d deleted from the BST.\n", data);

            // Prompt to display the updated tree
            printf("How would you like to display the updated BST?\n");
            printf("1) Inorder\n2) Preorder\n3) Postorder\n");
            int displayOpt;
            scanf("%d", &displayOpt);

            if (displayOpt == 1) {
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
            } else if (displayOpt == 2) {
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
            } else if (displayOpt == 3) {
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
            } else {
                printf("Invalid option.\n");
            }
        } else if (opt == 6) {
            printf("Exiting the program.\n");
            break; 
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}
