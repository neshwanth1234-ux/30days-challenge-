#include <stdio.h>

int main() {
    int grid[6][6], size, limit;
    int rows[6] = {0}, columns[6] = {0};
    int largest = -1, aboveLimit = 0, border = 0;
    int diagonal1 = 0, diagonal2 = 0, hotspots = 0;

    do {
        printf("Grid size (3-6): ");
        scanf("%d", &size);
    } while (size < 3 || size > 6);

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            do {
                printf("Score at (%d,%d), 0-100: ", r + 1, c + 1);
                scanf("%d", &grid[r][c]);
            } while (grid[r][c] < 0 || grid[r][c] > 100);
        }
    }

    do {
        printf("Threshold (1-100): ");
        scanf("%d", &limit);
    } while (limit < 1 || limit > 100);

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            int score = grid[r][c];

            rows[r] += score;
            columns[c] += score;
            if (score > largest) largest = score;
            if (score >= limit) aboveLimit++;
            if (r == 0 || c == 0 || r == size - 1 || c == size - 1)
                border += score;
            if (r == c) diagonal1 += score;
            if (r + c == size - 1) diagonal2 += score;
        }
    }

    for (int r = 0; r < size; r++)
        printf("Row %d total: %d\n", r + 1, rows[r]);

    for (int c = 0; c < size; c++)
        printf("Column %d total: %d\n", c + 1, columns[c]);

    printf("Highest row(s): ");
    for (int r = 0; r < size; r++) {
        int highest = 1;
        for (int k = 0; k < size; k++)
            if (rows[k] > rows[r]) highest = 0;
        if (highest) printf("%d ", r + 1);
    }

    printf("\nHighest column(s): ");
    for (int c = 0; c < size; c++) {
        int highest = 1;
        for (int k = 0; k < size; k++)
            if (columns[k] > columns[c]) highest = 0;
        if (highest) printf("%d ", c + 1);
    }

    printf("\nHighest score: %d at ", largest);
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            if (grid[r][c] == largest)
                printf("(%d,%d) ", r + 1, c + 1);

    for (int r = 1; r < size - 1; r++)
        for (int c = 1; c < size - 1; c++)
            if (grid[r][c] >= limit &&
                grid[r][c] > grid[r-1][c] &&
                grid[r][c] > grid[r+1][c] &&
                grid[r][c] > grid[r][c-1] &&
                grid[r][c] > grid[r][c+1]) {
                hotspots++;
                printf("\nHotspot at (%d,%d)", r + 1, c + 1);
            }

    printf("\nCells at/above threshold: %d\n", aboveLimit);
    printf("Diagonal totals: %d and %d\n", diagonal1, diagonal2);
    printf("Diagonals are %s\n",
           diagonal1 == diagonal2 ? "balanced" : "not balanced");
    printf("Boundary total: %d\n", border);
    if (hotspots == 0) printf("No local hotspot found\n");

    if (hotspots > 0) printf("CRITICAL\n");
    else if (aboveLimit >= size) printf("WARNING\n");
    else printf("NORMAL\n");

    return 0;
}
