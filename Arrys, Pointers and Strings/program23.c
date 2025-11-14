//Write a C program to search for a given element using linear search.
#include<stdio.h>
int main(){
    int arr[100], n, element, i, found = 0, index = -1;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("\nEnter the element to search for: ");
    scanf("%d", &element);
    
    // Linear search for the element
    for(i = 0; i < n; i++){
        if(arr[i] == element){
            found = 1;
            index = i;
            break;
        }
    }
    
    if(found){
        printf("Element %d found at index %d.\n", element, index);
    } else {
        printf("Element %d not found in the array.\n", element);
    }
    
    return 0;
}   