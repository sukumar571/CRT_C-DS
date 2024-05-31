#include <stdio.h>
#include <ctype.h> // For isalpha and isdigit functions
#include <string.h>

void reverseString(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        // Skip special characters and numbers
        while (!isalpha(str[start]) && !isdigit(str[start])) {
            start++;
        }
        while (!isalpha(str[end]) && !isdigit(str[end])) {
            end--;
        }

        // Swap characters
        if (start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }
}

int main() {
    char input[100]; // Assuming input string won't exceed 100 characters

    printf("Enter a string: ");
    scanf("%s", input);

    reverseString(input);

    printf("Reversed string: %s\n", input);

    return 0;
}
