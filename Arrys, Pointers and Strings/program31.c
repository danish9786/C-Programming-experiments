//Write a C program to count vowels, consonants, digits, and spaces in a string.

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isVowel(char ch){
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main(){
    char str[200];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0, others = 0;
    int i;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
    
    printf("\nInput string: %s\n", str);
    
    // Count each type of character
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            spaces++;
        }
        else if(isdigit(str[i])){
            digits++;
        }
        else if(isalpha(str[i])){
            if(isVowel(str[i])){
                vowels++;
            }
            else{
                consonants++;
            }
        }
        else{
            others++;
        }
    }
    
    // Display results
    printf("\n--- Character Count ---\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    printf("Other characters: %d\n", others);
    printf("Total characters: %d\n", strlen(str));
    
    return 0;
}
