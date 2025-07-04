#include <stdio.h>

int main()
{
    int arr_size,ar_val,i,n_val,index;
    printf("Please enter the size of array:\n");
    scanf("%d",&arr_size);

    int arr[arr_size];

    for (i=0;i<arr_size;i++)
    {
        printf("enter the value of element %d:  ",i+1);
        scanf("%d",&ar_val);
        arr[i]=ar_val;
    }

    printf("The array has been created \n");
    
    for (i=0;i<arr_size;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");

    printf("Please enter the element you want to search : ");
    scanf("%d",&n_val);
    int flag=0;
    for (i=0;i<=arr_size-1;i++)
    {
        if(arr[i]==n_val)
        {
            flag=1;
            index=i;
            break;
        }
    }
    if(flag==1)
    {
        printf("%d is presrnt at index %d in the array",n_val,index);
    }else
    {
        printf("%d is not presrnt in the array",n_val);
    }

    return 0;    
}