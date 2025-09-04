int main() {
    int vote1 = 0, vote2 = 0, vote3 = 0;
    char choice, cont = 'y';

    while (cont != 'n') {
        printf("\nVote for your candidate (1/2/3): ");
        scanf(" %c", &choice);

        if (choice == '1') vote1++;
        else if (choice == '2') vote2++;
        else if (choice == '3') vote3++;
        else printf("Invalid choice!\n");

        printf("Do you want to continue voting? (y/n): ");
        scanf(" %c", &cont);
    }

    printf("\nVoting Results:\n");
    printf("Candidate 1: %d votes\n", vote1);
    printf("Candidate 2: %d votes\n", vote2);
    printf("Candidate 3: %d votes\n", vote3);

    return 0;
}
