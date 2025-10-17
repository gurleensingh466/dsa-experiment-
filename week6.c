#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

// Function prototypes
void getInput(char text[], char pattern[], char replace[]);
int length(const char str[]);
int matchAt(const char text[], const char pattern[], int start);
void substitute(char text[], char pattern[], char replace[]);

int main() {
    char text[SIZE], pattern[SIZE], replace[SIZE];

    // Read user input
    getInput(text, pattern, replace);

    // Perform substitution
    substitute(text, pattern, replace);

    return 0;
}

// Function to read the main string, pattern, and replacement
void getInput(char text[], char pattern[], char replace[]) {
    printf("Enter the main text: ");
    fgets(text, SIZE, stdin);
    text[length(text)-1] = '\0';  // strip newline

    printf("Enter the substring to search: ");
    fgets(pattern, SIZE, stdin);
    pattern[length(pattern)-1] = '\0';

    printf("Enter the replacement text: ");
    fgets(replace, SIZE, stdin);
    replace[length(replace)-1] = '\0';
}

// Function to find length of a string
int length(const char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

// Function to check if pattern matches at a given position
int matchAt(const char text[], const char pattern[], int start) {
    int i = 0;
    while (pattern[i] != '\0') {
        if (text[start + i] != pattern[i])
            return 0;  // mismatch
        i++;
    }
    return 1;  // full match
}

// Function to replace all occurrences of pattern with replacement
void substitute(char text[], char pattern[], char replace[]) {
    char output[SIZE];
    int i = 0, j = 0;
    int lenText = length(text);
    int lenPat  = length(pattern);
    int lenRep  = length(replace);
    int replaced = 0;

    while (i < lenText) {
        if (matchAt(text, pattern, i)) {
            for (int k = 0; k < lenRep; k++)
                output[j++] = replace[k];
            i += lenPat;   // skip the pattern
            replaced = 1;
        } else {
            output[j++] = text[i++];
        }
    }
    output[j] = '\0';

    if (replaced)
        printf("\nUpdated text: %s\n", output);
    else
        printf("\nPattern not found in the text.\n");
}
