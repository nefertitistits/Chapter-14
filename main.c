#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to remove leading and trailing whitespaces from a string
void trim(char *str) {
    int start = 0, end = strlen(str) - 1;

    // Removing leading whitespaces
    while (isspace(str[start]))
        start++;

    // Removing trailing whitespaces
    while (end > start && isspace(str[end]))
        end--;

    // Shift the non-space characters to the beginning of the string
    for (int i = start; i <= end; i++)
        str[i - start] = str[i];

    // Null-terminate the string
    str[end - start + 1] = '\0';
}

// Function to extract the last name from a string containing first name and last name
char *extractLastName(const char *fullName) {
    const char *lastSpace = strrchr(fullName, ' ');
    if (lastSpace == NULL)
        return ""; // No space found, returning an empty string

    // Returning the substring after the last space
    return strdup(lastSpace + 1);
}

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
}

// Function to get the first word from a string and return the remainder
char *getFirstWord(char *str) {
    char *remainder = strchr(str, ' ');

    // If no space found, return an empty string
    if (remainder == NULL)
        return "";

    // Null-terminate the first word
    *remainder = '\0';

    // Return the remainder after the space
    return remainder + 1;
}

int main() {
    char fullName[100];
    printf("Enter your first name followed by a space and then your last name: ");
    fgets(fullName, sizeof(fullName), stdin);

    // Removing leading and trailing whitespaces
    trim(fullName);

    printf("Trimmed full name: %s\n", fullName);

    // Extracting the last name
    char *lastName = extractLastName(fullName);
    printf("Last name: %s\n", lastName);

    // Converting the full name to uppercase
    toUpperCase(fullName);
    printf("Full name in uppercase: %s\n", fullName);

    // Getting the first word and its remainder
    char *remainder = getFirstWord(fullName);
    printf("First word: %s\n", fullName);
    printf("Remainder: %s\n", remainder);

    // Freeing dynamically allocated memory
    free(lastName);

    return 0;
}

