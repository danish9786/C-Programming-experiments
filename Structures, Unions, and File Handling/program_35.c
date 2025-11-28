// Write a C program to reverse the first n characters in a file.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char *buffer;
    int n, i;

    file = fopen("file1.txt", "r+");
    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("Enter the number of characters to reverse: ");
    scanf("%d", &n);

    buffer = (char *)malloc(n + 1);
    if (buffer == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    fread(buffer, sizeof(char), n, file);
    buffer[n] = '\0';

    // Reverse the buffer
    for (i = 0; i < n / 2; i++)
    {
        char temp = buffer[i];
        buffer[i] = buffer[n - i - 1];
        buffer[n - i - 1] = temp;
    }

    fseek(file, 0, SEEK_SET);
    fwrite(buffer, sizeof(char), n, file);

    printf("First %d characters reversed successfully.\n", n);

    free(buffer);
    fclose(file);

    return 0;
}