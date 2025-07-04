 #include <stdio.h>
#include <stdlib.h>

void options(){
    printf("1)Inorder traversal of the BST:\n ");
    printf("2)Preorder traversal of the BST:\n ");
    printf("3)Postorder traversal of the BST:\n ");
    printf("4)search the element\n");
}

struct node
{
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

 struct node*insert( struct node*root, int data){
    if (root==NULL){
        return createNode(data);
    }
 if(data < root->data){
    root->left=insert(root->left, data);
 }else if(data > root->data) {
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

int main(){
    struct node* root = NULL;
    int n, data, opt;

printf("enter the number of elements u want to insert:");
scanf("%d",&n);

for(int i=0; i<n; i++){
    printf("enter the element %d ",i+1);
    scanf("%d", &data);
    root = insert(root, data);
}

options();
scanf("%d",&opt);

if(opt==1){
    inorder(root);
    printf("\n");
}

 else if(opt==2){
    preorder(root);
    printf("\n");
}

 else if(opt==3){
    postorder(root);
    printf("\n");
}

else if (opt == 4) {
        printf("Enter the element to search: ");
        scanf("%d", &data);
        struct node* result = searchNode(root, data);
        if (result != NULL) {
            printf("Element %d found in the BST.\n", result->data);
        } else {
            printf("Element %d not found in the BST.\n", data);
        }
    } else {
        printf("Invalid option.\n");
    }
    return 0;
    

}







 

