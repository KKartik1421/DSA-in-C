#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

int main()
{
    node *head = NULL, *tail = NULL;
    int i, n_size;

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
            new_node->prev = NULL;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    printf("The linked list has been created.\n");
    printf("HEAD -> ");

    node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}
