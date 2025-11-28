// Write a C program to copy the contents of one file to another file.
#include<stdio.h>

int main()
{
    FILE *sourceFile, *destinationFile;
    char ch;

    sourceFile = fopen("file1.txt", "r");
    if (sourceFile == NULL)
    {
        printf("Unable to open source file.\n");
        return 1;
    }

    destinationFile = fopen("file2.txt", "w");
    if (destinationFile == NULL)
    {
        printf("Unable to open destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    while ((ch = fgetc(sourceFile)) != EOF)
    {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}