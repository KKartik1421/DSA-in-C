#include <stdio.h>

int main() {
    int n, pos, value, i;
    
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];  
    
    
    printf("Enter the elements of the array (use 0 for empty spots):\n");
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Check if there's room for insertion (look for at least one '0' in the array)
    int is_full = 1;
    for(i = 0; i < n; i++) {
        if(arr[i] == 0) {
            is_full = 0;
            break;
        }
    }

    if(is_full) {
        printf("\nThe array is full. No insertion can be made.\n");
    } else {

        printf("Enter the value to insert: ");
        scanf("%d", &value);
    
        printf("Enter the position where the value should be inserted (1 to %d): ", n);
        scanf("%d", &pos);
        
        // Adjust the position for 0-based indexing in the array
        pos--;
        
        // Shift elements to the right starting from the desired position
        for (i = n - 1; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        
        // Insert the new value at the desired position
        arr[pos] = value;

        // Print the modified array
        printf("\n\nModified array after inserting %d at position %d:\n", value, pos + 1);
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
