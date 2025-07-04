#include <stdio.h>
#include <stdlib.h>

void options()
{
    printf("Select from where you want to perform delete\n");
    printf("1) At Beginning (Will delete first element)\n");
    printf("2) At Middle\n");
    printf("3) At End\n");
}

typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    node *head = NULL, *tail = NULL;
    int i, n_size, opt, pos;

    printf("How many elements do you want to insert: ");
    scanf("%d", &n_size);

    // Create the linked list
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
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Display the created linked list
    printf("The linked list has been created.\nHEAD -> ");
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    options();
    scanf("%d", &opt);

    if (opt == 1)
    {
        // Deletion at the beginning
        if (head != NULL)
        {
            node *temp = head;
            head = head->next;
            free(temp);
        }
    }
    else if (opt == 2)
    {
        // Deletion in the middle
        printf("Enter the position to delete (1 to %d): ", n_size);
        scanf("%d", &pos);

        if (pos < 1 || pos > n_size)
        {
            printf("Invalid position.\n");
        }
        else if (pos == 1)
        {
            // If position is 1, it's the same as deleting the first element
            node *temp = head;
            head = head->next;
            free(temp);
        }
        else
        {
            node *prev = head;
            for (i = 1; i < pos - 1; i++)
            {
                prev = prev->next;
            }

            node *to_delete = prev->next;
            prev->next = to_delete->next;
            free(to_delete);
        }
    }
    else if (opt == 3)
    {
        // Deletion at the end
        if (head != NULL)
        {
            if (head->next == NULL)
            {
                // If there's only one element, head becomes NULL
                free(head);
                head = NULL;
            }
            else
            {
                node *temp = head;
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                node *to_delete = temp->next;
                temp->next = NULL;
                free(to_delete);
            }
        }
    }
    else
    {
        printf("Invalid Option\n");
    }
    if (opt==1||opt==2||opt==3)
    {
        // Display the updated linked list
        printf("The linked list has been updated.\nHEAD -> ");
        temp = head;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    return 0;
}
