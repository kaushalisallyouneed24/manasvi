#include <stdio.h>
#include <string.h>

int main() {
    char str[1000], longest[100], word[100];
    int i = 0, j = 0, maxLen = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    while(1) {
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
            word[j++] = str[i];  // Collect characters of a word
        } else {
            word[j] = '\0';  // End current word
            if(j > maxLen) {
                maxLen = j;
                strcpy(longest, word);
            }
            j = 0;  // Reset for next word
        }
        if(str[i] == '\0') break;  // End of string
        i++;
    }

    printf("Longest word: %s\n", longest);
    printf("Length of longest word: %d\n", maxLen);

    return 0;
}
