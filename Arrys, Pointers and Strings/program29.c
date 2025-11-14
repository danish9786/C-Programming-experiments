//Write a C program to copy a string with and without library function.

#include<stdio.h>
#include<string.h>

// Function to copy string without library function
void stringCopy(char dest[], char src[]){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Add null terminator
}

int main(){
    char source[100], dest1[100], dest2[100];
    
    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);
    
    // Remove newline character if present
    if(source[strlen(source)-1] == '\n'){
        source[strlen(source)-1] = '\0';
    }
    
    printf("\nOriginal string: %s\n", source);
    
    // Method 1: Copy without library function
    stringCopy(dest1, source);
    printf("\nCopied string (without library function): %s\n", dest1);
    
    // Method 2: Copy using library function (strcpy)
    strcpy(dest2, source);
    printf("Copied string (using strcpy): %s\n", dest2);
    
    return 0;
}
