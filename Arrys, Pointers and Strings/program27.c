//Write a C program to reverse the elements of an array using pointers.

#include<stdio.h>

void reverseArray(int *arr, int n){
    int *start = arr;           // Pointer to the first element
    int *end = arr + n - 1;     // Pointer to the last element
    int temp;
    
    // Swap elements from both ends moving towards center
    while(start < end){
        // Swap values using pointers
        temp = *start;
        *start = *end;
        *end = temp;
        
        // Move pointers towards center
        start++;
        end--;
    }
}

int main(){
    int arr[100], n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    // Reverse the array using pointers
    reverseArray(arr, n);
    
    printf("\n\nReversed array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
