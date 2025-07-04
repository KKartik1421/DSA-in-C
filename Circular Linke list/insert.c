 #include <stdio.h>
#include <stdlib.h>

void options()
{
    printf("Select which operation you want to perform\n");
    printf("1) Insert At Beginning\n");
    printf("2) Insert At Middle\n");
    printf("3) Insert At End\n");
    printf("4) Delete At Beginning\n");
    printf("5) Delete At End\n");
    printf("6) Delete At middle\n");
}

typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    node *head = NULL, *tail = NULL;
    int i, n_size,opt,val,pos;
    
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

    options();
    scanf("%d",&opt);

    if(opt==1)
    {
        //Insert at begining
        node *new_node = (node *)malloc(sizeof(node));
        printf("Please enter value of new node: ");
        scanf("%d", &new_node->data);
        new_node->next=head;
        head=new_node;
        tail->next=head;
    }
    else if(opt==2)
    {
        //insertion at middle
        node *new_node = (node*)malloc(sizeof(node));
         printf("Enter the value you want to insert: ");
        scanf("%d", &val);

        new_node->data = val;
        new_node->next = NULL;

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
    else if(opt==3)
    {
        //insertion at last
        node *new_node = (node *)malloc(sizeof(node));
        printf("Please enter value of new node: ");
        scanf("%d", &new_node->data);
        tail->next=new_node;
        tail=new_node;
        tail->next=head;

    }    

    else if(opt==4)
    {
      if(head==NULL)
      {
        printf("list is empty\n");
      }
      else{
        node * temp=head;
        while(temp->next != head)
        {
            temp=temp->next;
        }
        node * q = head;
        head=q->next;
        temp->next=head;
        free(q);
      }
    }
     else if (opt == 5)
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
                while (temp->next->next != head)
                {
                    temp = temp->next;
                }

                node *to_delete = temp->next;
                temp->next = head;
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
     else
    {
        printf("Please select a valid option\n");
    }

    if(opt==1||opt==2||opt==3||opt==4||opt==5||opt==6)
    {
       printf("The linked list has been updated.\n");
        printf(".....-> HEAD -> ");
    
        node *temp = head;
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }while (temp != head);
    
        printf("HEAD->.....\n\n"); 
    }
    return 0;
}
   

        

    

    
   