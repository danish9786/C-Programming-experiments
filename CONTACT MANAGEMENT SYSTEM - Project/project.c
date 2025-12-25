/*
 * CONTACT MANAGEMENT SYSTEM
 * A simple C program demonstrating core programming concepts
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Structure Definition
struct Contact {
    int id;
    char name[50];
    char phone[15];
    char email[50];
    char address[100];
};

// Function Prototypes
void createFile();
void addContact();
void displayAllContacts();
void searchContact();
void updateContact();
void deleteContact();
void displayMenu();
int getContactCount();
void clearInputBuffer();
void toLowerCase(char *str);
int isValidPhone(char *phone);

// Static variable to track contacts
static int totalContacts = 0;

// Main Function
int main()
{
    int choice;
    
    createFile();
    
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayAllContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                updateContact();
                break;
            case 5:
                deleteContact();
                break;
            case 0:
                printf("\nThank you for using Contact Manager!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar();
        }
        
    } while(choice != 0);
    
    return 0;
}

// Create file if it doesn't exist
void createFile()
{
    FILE *fp = fopen("contacts.txt", "a+");
    if(fp == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }
    fclose(fp);
}

// Add a new contact
void addContact()
{
    struct Contact c;
    FILE *fp;
    
    printf("\n=== ADD NEW CONTACT ===\n");
    
    // Generate unique ID using static variable
    static int idCounter = 0;
    if(idCounter == 0) {
        idCounter = getContactCount() + 1;
    } else {
        idCounter++;
    }
    c.id = idCounter;
    
    // Get contact details
    printf("Enter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0';
    
    // Phone validation using do-while loop
    do {
        printf("Enter Phone (10 digits): ");
        fgets(c.phone, sizeof(c.phone), stdin);
        c.phone[strcspn(c.phone, "\n")] = 0;
        
        if(isValidPhone(c.phone)) {
            break;
        } else {
            printf("Invalid phone! Try again.\n");
        }
    } while(1);
    
    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = 0;
    
    printf("Enter Address: ");
    fgets(c.address, sizeof(c.address), stdin);
    c.address[strcspn(c.address, "\n")] = 0;
    
    // Write to file
    fp = fopen("contacts.txt", "a");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    fprintf(fp, "%d|%s|%s|%s|%s\n", c.id, c.name, c.phone, c.email, c.address);
    fclose(fp);
    totalContacts++;
    
    printf("\nContact added successfully! ID: %d\n", c.id);
}

// Display all contacts
void displayAllContacts()
{
    FILE *fp = fopen("contacts.txt", "r");
    struct Contact c;
    int count = 0;
    
    if(fp == NULL) {
        printf("No contacts found!\n");
        return;
    }
    
    printf("\n========== ALL CONTACTS ==========\n");
    printf("%-5s %-20s %-15s %-25s\n", "ID", "Name", "Phone", "Email");
    printf("--------------------------------------------------\n");
    
    while(fscanf(fp, "%d|%49[^|]|%14[^|]|%49[^|]|%99[^\n]\n",
                  &c.id, c.name, c.phone, c.email, c.address) == 5) {
        printf("%-5d %-20s %-15s %-25s\n", c.id, c.name, c.phone, c.email);
        count++;
    }
    
    fclose(fp);
    printf("\nTotal Contacts: %d\n", count);
}

// Search for a contact by name
void searchContact()
{
    FILE *fp;
    struct Contact c;
    char searchName[50];
    int found = 0;
    
    printf("\n=== SEARCH CONTACT ===\n");
    printf("Enter name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    
    // Use pointer for string manipulation
    char *pSearch = searchName;
    toLowerCase(pSearch);
    
    fp = fopen("contacts.txt", "r");
    if(fp == NULL) {
        printf("No contacts found!\n");
        return;
    }
    
    printf("\n%-5s %-20s %-15s %-25s\n", "ID", "Name", "Phone", "Email");
    printf("--------------------------------------------------\n");
    
    while(fscanf(fp, "%d|%49[^|]|%14[^|]|%49[^|]|%99[^\n]\n",
                  &c.id, c.name, c.phone, c.email, c.address) == 5) {
        
        char tempName[50];
        strcpy(tempName, c.name);
        toLowerCase(tempName);
        
        // String comparison using strstr
        if(strstr(tempName, pSearch) != NULL) {
            printf("%-5d %-20s %-15s %-25s\n", c.id, c.name, c.phone, c.email);
            found = 1;
        }
    }
    
    fclose(fp);
    
    if(!found) {
        printf("No contact found with name: %s\n", searchName);
    }
}

// Update an existing contact
void updateContact()
{
    FILE *fp, *temp;
    struct Contact c;
    int searchId, found = 0;
    
    printf("\n=== UPDATE CONTACT ===\n");
    printf("Enter Contact ID to update: ");
    scanf("%d", &searchId);
    clearInputBuffer();
    
    fp = fopen("contacts.txt", "r");
    temp = fopen("temp.txt", "w");
    
    if(fp == NULL) {
        printf("No contacts found!\n");
        return;
    }
    
    if(temp == NULL) {
        printf("Error creating temp file!\n");
        fclose(fp);
        return;
    }
    
    while(fscanf(fp, "%d|%49[^|]|%14[^|]|%49[^|]|%99[^\n]\n",
                  &c.id, c.name, c.phone, c.email, c.address) == 5) {
        
        if(c.id == searchId) {
            found = 1;
            printf("\nCurrent Details:\n");
            printf("Name: %s\nPhone: %s\nEmail: %s\n", c.name, c.phone, c.email);
            
            printf("\nEnter new details:\n");
            printf("Name: ");
            fgets(c.name, sizeof(c.name), stdin);
            c.name[strcspn(c.name, "\n")] = 0;
            
            printf("Phone: ");
            fgets(c.phone, sizeof(c.phone), stdin);
            c.phone[strcspn(c.phone, "\n")] = 0;
            
            printf("Email: ");
            fgets(c.email, sizeof(c.email), stdin);
            c.email[strcspn(c.email, "\n")] = 0;
            
            printf("Contact updated successfully!\n");
        }
        
        fprintf(temp, "%d|%s|%s|%s|%s\n", c.id, c.name, c.phone, c.email, c.address);
    }
    
    fclose(fp);
    fclose(temp);
    
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
    
    if(!found) {
        printf("Contact ID %d not found!\n", searchId);
    }
}

// Delete a contact
void deleteContact()
{
    FILE *fp, *temp;
    struct Contact c;
    int searchId, found = 0;
    
    printf("\n=== DELETE CONTACT ===\n");
    printf("Enter Contact ID to delete: ");
    scanf("%d", &searchId);
    clearInputBuffer();
    
    fp = fopen("contacts.txt", "r");
    temp = fopen("temp.txt", "w");
    
    if(fp == NULL) {
        printf("No contacts found!\n");
        return;
    }
    
    if(temp == NULL) {
        printf("Error creating temp file!\n");
        fclose(fp);
        return;
    }
    
    while(fscanf(fp, "%d|%49[^|]|%14[^|]|%49[^|]|%99[^\n]\n",
                  &c.id, c.name, c.phone, c.email, c.address) == 5) {
        
        if(c.id == searchId) {
            found = 1;
            printf("Deleted: %s (%s)\n", c.name, c.phone);
            totalContacts--;
            continue;
        }
        
        fprintf(temp, "%d|%s|%s|%s|%s\n", c.id, c.name, c.phone, c.email, c.address);
    }
    
    fclose(fp);
    fclose(temp);
    
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
    
    if(!found) {
        printf("Contact ID %d not found!\n", searchId);
    }
}

// Display menu
void displayMenu()
{
    printf("\n");
    printf("==== CONTACT MANAGEMENT SYSTEM ====\n");
    printf("1. Add Contact\n");
    printf("2. Display All Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Update Contact\n");
    printf("5. Delete Contact\n");
    printf("0. Exit\n");
    printf("===================================\n");
}

// Get total contact count from file
int getContactCount()
{
    FILE *fp = fopen("contacts.txt", "r");
    struct Contact c;
    int count = 0;
    
    if(fp == NULL) return 0;
    
    while(fscanf(fp, "%d|%49[^|]|%14[^|]|%49[^|]|%99[^\n]\n",
                  &c.id, c.name, c.phone, c.email, c.address) == 5) {
        count++;
    }
    
    fclose(fp);
    return count;
}

// Clear input buffer
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Convert string to lowercase using pointer
void toLowerCase(char *str)
{
    while(*str) {
        *str = tolower(*str);
        str++;
    }
}

// Validate phone number
int isValidPhone(char *phone)
{
    int len = strlen(phone);
    
    if(len < 10 || len > 15) return 0;
    
    for(int i = 0; i < len; i++) {
        if(!isdigit(phone[i])) {
            return 0;
        }
    }
    return 1;
}
