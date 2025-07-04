 #include <stdio.h>
#include <stdlib.h>

void options()
{
    printf("Select which operation you want to perform \n");
    printf("1) Insert At Beginning\n");
    printf("2) Insert At Middle\n");
    printf("3) Insert At End\n");
    printf("4) Delete at the beginning\n");
    printf("5) Delete at the end\n");
    printf("6) Delete at the middle\n");

}

typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    node *head = NULL, *tail = NULL;
    int i, n_size, opt, val, pos;

    printf("How many elements do you want to insert: ");
    scanf("%d", &n_size);

    // Create initial linked list
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

    printf("The linked list has been created.\n");

    // Print initial list
    node *temp = head;
    printf("HEAD ->");
    while (temp != NULL)
    {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");

    // Choose performance option
    options();
    scanf("%d", &opt);

    
    if (opt == 1)
    {
        printf("Enter the value you want to insert: ");
    scanf("%d", &val);

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;

        // Insert at the beginning
        new_node->next = head;
        head = new_node;
    }
    else if (opt == 2)
    {
        printf("Enter the value you want to insert: ");
    scanf("%d", &val);

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;

        // Insert at the middle
        printf("Enter the position after which to insert (1 to %d): ", n_size);
        scanf("%d", &pos);

        if (pos < 1 || pos > n_size)
        {
            printf("Invalid position.\n");
            free(new_node);
        }
        else
        {
            node *temp = head;
            for (i = 1; i < pos; i++)
            {
                temp = temp->next;
            }

            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    else if (opt == 3)
    {
        printf("Enter the value you want to insert: ");
    scanf("%d", &val);

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;

        // Insert at the end
        tail->next = new_node;
        tail = new_node;
    }
    else if (opt==4)
    {
        if (head != NULL)
        {
            node *temp = head;
            head = head->next;
            free(temp);
        }
    }
    else if (opt==5)
    {
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

     else if (opt == 6)
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
            node *q = head;
            for (i = 1; i < pos - 1; i++)
            {
                q = q->next;
            }

            node *to_delete = q->next;
            q->next = to_delete->next;
            free(to_delete);
        }
    }
    
                
    else
    {
        printf("Please select a valid option\n");
    }

    // Print updated list
    printf("The linked list has been updated.\n");
    temp = head;
    printf("HEAD ->");
    while (temp != NULL)
    {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");

    return 0;
}
