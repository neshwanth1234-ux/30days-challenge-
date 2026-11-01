ALGORITHM
1. Start
2. Enter grid size n. Repeat until n is from 3 to 6.
3. Enter the risk score for each cell. Repeat if a score is outside 0 to 100.
4. Enter threshold t. Repeat until t is from 1 to 100.
5. Find and display each row and column total. Show all rows and columns tied for the highest total.
6. Find and display the highest score and every position where it appears. Count the cells with scores at least t.
7. Find and display both diagonal totals. Report whether they are balanced.
8. Find and display the boundary total, counting each cell once.
9. Check each inside cell. Count it as a hotspot if its score is at least t and greater than its top, bottom, left, and right neighbours.
10. Display critical if a hotspot exists. Otherwise, display warning if at least n cells have scores at least t. If neither condition is true, display normal.
11. Stop
