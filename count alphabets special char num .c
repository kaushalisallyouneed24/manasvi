int main() {
    char str[1000];
    int i, alphabets = 0, digits = 0, special = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++) {
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
            alphabets++;
        else if(str[i]>='0' && str[i]<='9')
            digits++;
        else if(str[i] != ' ' && str[i] != '\n')
            special++;
    }

    printf("Alphabets: %d\n", alphabets);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", special);

    return 0;
}
