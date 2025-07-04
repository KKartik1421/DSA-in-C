#include <stdio.h>

// Function to find the index of the last non-zero element
int l_ind(int arr[], int arr_size) 
{
    int i;
    for (i = arr_size - 1; i >= 0; i--) 
    {
        if (arr[i] != 0) {
            return i;  // Return the last non-zero index
        }
    }
    return -1;  // Return -1 if no non-zero element is found
}

int main()
{
    int arr_size, ar_val, i, j, n_val, index, l_index;
    
    
    printf("Please enter the size of array:\n");
    scanf("%d", &arr_size);

    int arr[arr_size];  

    
    for (i = 0; i < arr_size; i++)
    {
        printf("Enter the value of element %d: ", i + 1);
        scanf("%d", &ar_val);
        arr[i] = ar_val;
    }

    printf("The array has been created:\n");
    
    for (i = 0; i < arr_size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");

    
    printf("Please enter the element you want to delete: ");
    scanf("%d", &n_val);

    int flag = 0;

    // Search for the element in the array
    for (i = 0; i < arr_size; i++)
    {
        if (arr[i] == n_val)
        {
            flag = 1;
            index = i;
            break;
        }
    }

    if (flag == 1)
    {
        // Find the index of the last non-zero element
        l_index = l_ind(arr, arr_size);

        // Shift elements to the left to delete the element
        for (i = index; i < l_index; i++)
        {
            arr[i] = arr[i + 1];
        }
        
        arr[l_index] = 0;  // Set the last element to 0

        //prints the updated array
        printf("Updated array:\n");
        for (j = 0; j < arr_size; j++)
        {
            printf(" %d ", arr[j]);
        }
        printf("\n");
    
    } 
    else
    {
        printf("%d is not present in the array\n", n_val);
    }

    return 0;    
}
