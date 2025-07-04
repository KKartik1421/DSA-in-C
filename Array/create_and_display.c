#include <stdio.h>

int main()
{
    int arr_size,ar_val,i;
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

    return 0;
}