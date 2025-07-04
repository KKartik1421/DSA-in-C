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
    int i, n_size, val, flag;
    
    printf("How many elements do you want to insert: ");
    scanf("%d", &n_size);
    
    for (i = 1; i <= n_size; i++)
    {
        node *new_node = (node *)malloc(sizeof(node));
        printf("Please enter value %d: ", i);
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            tail->next=head;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
            tail->next=head;
        }
    }
    
    printf("The linked list has been created.\n");
    printf(".....-> HEAD -> ");
    
    node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while (temp != head);
    
    printf("HEAD->.....\n\n");

    printf("Enter the element you want to search :");
    scanf("%d",&val);
    node *q=head;
    flag=0;
    do
    {
        if(q->data==val)
        {
            flag=1;
            break;
        }
        q=q->next;
    } while(q != head);

    if (flag == 1) {
        printf("%d is present in the list\n", val);
    } else {
        printf("%d is not present in the list\n", val);
    }

    return 0;
}
    

   