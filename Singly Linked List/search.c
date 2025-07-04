#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    node *head = NULL, *tail = NULL;
    int i, n_size,val,flag;
    
    printf("How many elements do you want to insert: ");
    scanf("%d", &n_size);
    
    for (i = 1; i <= n_size; i++)
    {
        node *ew_node = (node *)malloc(sizeof(node));
        printf("Please enter value %d: ", i);
        scanf("%d", &ew_node->data);
        ew_node->next = NULL;
        
        if (head == NULL)
        {
            head = ew_node;
            tail = ew_node;
        }
        else
        {
            tail->next = ew_node;
            tail = ew_node;
        }
    }
    
    printf("The linked list has been created.\n");
    printf("Enter the element you want to search :");
    scanf("%d",&val);
    node *temp;
    temp=head;
    flag=0;
    while(temp != NULL)
    {
        if (temp->data==val)
        {
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==1)
    {
        printf("%d is present in list\n",val);
    }else
    {
        printf("%d is not present in list\n",val);
    }
    return 0;
}