#include <stdio.h>
#include <string.h>

int countWords(char str[]) {
    int i, words = 0;

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            words++;
        }
    }

    
    if(i > 0 && str[i-1] != ' ' && str[i-1] != '\n' && str[i-1] != '\t') {
        words++;
    }

    return words;
}

int main() {
    char str[1000];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int totalWords = countWords(str);

    printf("Total number of words: %d\n", totalWords);

    return 0;
}
