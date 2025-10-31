//Write a C program to insert an element in an array at a specific index.

#include<stdio.h>

int main(){
    int arr[100], n, element, index, i;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n\nEnter the element to insert: ");
    scanf("%d", &element);
    
    printf("Enter the index where you want to insert (0 to %d): ", n);
    scanf("%d", &index);
    
    // Validate index
    if(index < 0 || index > n){
        printf("Invalid index!\n");
        return 1;
    }
    
    // Shift elements to the right from the insertion point
    for(i = n; i > index; i--){
        arr[i] = arr[i-1];
    }
    
    // Insert the element at the specified index
    arr[index] = element;
    n++;
    
    printf("\nArray after insertion: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
