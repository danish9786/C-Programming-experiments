//Write a C program to find out if string is palindrome or not.

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isPalindrome(char str[]){
    int left = 0;
    int right = strlen(str) - 1;
    
    while(left < right){
        // Convert to lowercase for case-insensitive comparison
        if(tolower(str[left]) != tolower(str[right])){
            return 0;  // Not a palindrome
        }
        left++;
        right--;
    }
    return 1;  // Is a palindrome
}

int main(){
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
    
    printf("\nInput string: %s\n", str);
    
    if(isPalindrome(str)){
        printf("The string is a PALINDROME.\n");
    }
    else{
        printf("The string is NOT a palindrome.\n");
    }
    
    return 0;
}
