// Write a C program to find the length of a string using a pointer and library function

#include<stdio.h>
#include<string.h>

// Function to find string length using pointer
int stringLength(char *str){
    int length = 0;
    while(*str != '\0'){
        length++;
        str++;
    }
    return length;
}

int main(){
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
    
    // Method 1: Using pointer
    int len1 = stringLength(str);
    printf("\nLength using pointer: %d\n", len1);
    
    // Method 2: Using library function
    int len2 = strlen(str);
    printf("Length using library function (strlen): %d\n", len2);
    
    return 0;
}