//Write a C program to access array elements using pointers instead of indexing.
#include<stdio.h>

int main(){
    int arr[100], n, i;
    int *ptr;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    ptr = arr; // Pointer points to the first element of the array

    printf("Array elements accessed using pointers:\n");
    for(i = 0; i < n; i++){
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}