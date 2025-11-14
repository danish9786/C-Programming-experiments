//Write a C program to concatenate two strings with and without library function.

#include<stdio.h>
#include<string.h>

// Function to concatenate strings without library function
void stringConcat(char dest[], char src[]){
    int i = 0, j = 0;
    
    // Find the end of destination string
    while(dest[i] != '\0'){
        i++;
    }
    
    // Copy source string to the end of destination
    while(src[j] != '\0'){
        dest[i] = src[j];
        i++;
        j++;
    }
    
    dest[i] = '\0';  // Add null terminator
}

int main(){
    char str1[200], str2[100];
    char result1[200], result2[200];
    
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    
    // Remove newline character if present
    if(str1[strlen(str1)-1] == '\n'){
        str1[strlen(str1)-1] = '\0';
    }
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    
    // Remove newline character if present
    if(str2[strlen(str2)-1] == '\n'){
        str2[strlen(str2)-1] = '\0';
    }
    
    printf("\nFirst string: %s\n", str1);
    printf("Second string: %s\n", str2);
    
    // Method 1: Concatenate without library function
    strcpy(result1, str1);  // Copy first string to result1
    stringConcat(result1, str2);
    printf("\nConcatenated string (without library function): %s\n", result1);
    
    // Method 2: Concatenate using library function (strcat)
    strcpy(result2, str1);  // Copy first string to result2
    strcat(result2, str2);
    printf("Concatenated string (using strcat): %s\n", result2);
    
    return 0;
}
