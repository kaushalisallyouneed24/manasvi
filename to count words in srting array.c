// to count words in string array.
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int i, words = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            words++;
        }
}
    if(i > 0 && str[i-1] != ' ' && str[i-1] != '\n' && str[i-1] != '\t') {
        words++;
    }

    printf("Total number of words: %d\n", words);

    return 0;
}
