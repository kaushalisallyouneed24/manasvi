#include <stdio.h>

int main() {
    int premium_t = 200, standard_t = 150, eco_t = 100;
    int premium_s = 0, standard_s = 0, eco_s = 0;
    int total_cost = 0, total_tickets = 0, discount = 0;
    int choice;

    printf("Do you want to book a ticket? (1 for Yes / 0 for No): ");
    int proceed;
    scanf("%d", &proceed);

    if (proceed != 1) {
        printf("Thank you! Visit again.\n");
        return 0;
    }

    printf("\nWelcome to the Cinema!\n");
    printf("----- Seat Categories -----\n");
    printf("1. Premium  (₹200)\n");
    printf("2. Standard (₹150)\n");
    printf("3. Economy  (₹100)\n");
    printf("----------------------------\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the number of Premium tickets: ");
            scanf("%d", &premium_s);
            total_cost = premium_t * premium_s;
            total_tickets = premium_s;
            break;

        case 2:
            printf("Enter the number of Standard tickets: ");
            scanf("%d", &standard_s);
            total_cost = standard_t * standard_s;
            total_tickets = standard_s;
            break;

        case 3:
            printf("Enter the number of Economy tickets: ");
            scanf("%d", &eco_s);
            total_cost = eco_t * eco_s;
            total_tickets = eco_s;
            break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    // Apply 5% discount if tickets >= 5
    if (total_tickets >= 5) {
        discount = total_cost * 0.05;  // 5% discount
        total_cost -= discount;
        printf("You got a 5%% discount of ₹%d!\n", discount);
    }

    printf("Final total cost = ₹%d\n", total_cost);

    return 0;
}
