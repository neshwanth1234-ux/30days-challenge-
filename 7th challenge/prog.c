#include <stdio.h>

int main(void)
{
int n, a[15], r, valid = 1;
printf("Enter N (5 to 15): ");
scanf("%d", &n);

if (n < 5 || n > 15) {
printf("Invalid N\n");
valid = 0;
}

if (valid) {
printf("Enter ticket IDs:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &a[i]);
if (a[i] < 1 || a[i] > n)
valid = 0;
}

if (!valid) {
printf("Invalid ticket ID\n");
} else {
printf("Sequence: ");
for (int i = 0; i < n; i++)
printf("%d ", a[i]);

int missing = 0, duplicate = 0, m = 0, d = 0;
for (int id = 1; id <= n; id++) {
int count = 0;
for (int i = 0; i < n; i++)
if (a[i] == id) count++;

if (count == 0) { missing = id; m++; }
else if (count == 2) { duplicate = id; d++; }
else if (count != 1) valid = 0;
}

if (!valid || m != 1 || d != 1) {
printf("\nInvalid scan log\n");
} else {
int pairs = 0;
for (int i = 0; i < n; i++)
for (int j = i + 1; j < n; j++)
if (a[i] > a[j]) pairs++;

printf("\nMissing: %d, Duplicate: %d\n", missing, duplicate);
printf("Out-of-order pairs: %d\n", pairs);

printf("Enter last two registration digits: ");
scanf("%d", &r);

int target = r % n + 1, count = 0;
printf("Target %d positions: ", target);
for (int i = 0; i < n; i++)
if (a[i] == target) {
printf("%d ", i + 1);
count++;
}
printf("\nOccurrences: %d\n", count);
}
}
}

return 0;
}

