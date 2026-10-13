#include <stdio.h>

int main()
{
    int x, count = 0, total = 0;
    int small = 0, medium = 0, large = 0;

    do {
        printf("Enter expense: ");
        scanf("%d", &x);

        if (x < 0)
            printf("Invalid amount\n");
        else if (x > 0) {
            count++;
            total = total + x;

            if (x < 100) small = small + x;
            else if (x < 500) medium = medium + x;
            else large = large + x;
        }
    } while (x != 0);

    printf("Count: %d, Total: %d\n", count, total);
    printf("Small total: %d\nMedium total: %d\nLarge total: %d\n",
           small, medium, large);

    if (count > 0) printf("Average: %d\n", total / count);
    else printf("No valid expenses\n");

    return 0;
}


