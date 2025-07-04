#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

int main() {
    int arr_size;
    char arr[MAX_SIZE + 1]; 
    printf("Please enter the size of the array (up to %d):\n", MAX_SIZE);
    scanf("%d", &arr_size);

    // Clear the newline character from the buffer after reading arr_size
    scanf("%*c"); // This will read and discard the newline character

    printf("Enter the values of the elements (up to %d characters): ", arr_size);
    scanf("%s", arr);  
    printf("You entered:\n");
    for (int i = 0; i < arr_size && arr[i] != '\0'; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    return 0;
}
