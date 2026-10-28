
1.start
2. Read N.
3. If N < 5 or N > 15, display Invalid N and go to STOP.
4. Read the N ticket IDs.
5. If any ID is less than 1 or greater than N, display Invalid scan log and go to STOP.
6. Display the original ticket sequence.
7. Count each ID from 1 to N.
8. If there is not exactly one missing ID and one duplicated ID, display Invalid scan log and go to STOP.
9. Display the missing and duplicated IDs.
10. Compare every pair of positions. Count each pair where the earlier ID is greater than the later ID.
11. Display the out-of-order pair count.
12. Read the last two registration digits, R.
13. Calculate Target = (R % N) + 1.
14. Display the target’s positions and occurrence count.
15.stop
