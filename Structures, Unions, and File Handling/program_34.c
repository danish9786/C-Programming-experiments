// Write a C program to merge two files into a third file.

#include <stdio.h>

int main()
{
    FILE *file1, *file2, *mergedFile;
    char ch;

    file1 = fopen("file1.txt", "r");
    if (file1 == NULL)
    {
        printf("Unable to open file1.\n");
        return 1;
    }

    file2 = fopen("file2.txt", "r");
    if (file2 == NULL)
    {
        printf("Unable to open file2.\n");
        fclose(file1);
        return 1;
    }

    mergedFile = fopen("mergedFile.txt", "w");
    if (mergedFile == NULL)
    {
        printf("Unable to create merged file.\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    while ((ch = fgetc(file1)) != EOF)
    {
        fputc(ch, mergedFile);
    }

    while ((ch = fgetc(file2)) != EOF)
    {
        fputc(ch, mergedFile);
    }

    printf("Files merged successfully into mergedFile.txt.\n");

    fclose(file1);
    fclose(file2);
    fclose(mergedFile);

    return 0;
}