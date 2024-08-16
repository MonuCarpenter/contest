# Test Results - 2024-08-16 19:10:19
## Test case #1

### Status
<span style="color:red; font-weight:bold; font-size:larger;">Failed</span>

### Input
6
5 5
.....
.....
..#..
.....
.....
5 5
..#..
.###.
#####
.###.
..#..
5 6
......
......
.#....
###...
.#....
1 1
#
5 6
...#..
..###.
.#####
..###.
...#..
2 10
..........
...#......

### Output
55
before the loop
after the loop
---> ..#..
55
before the loop
after the loop
---> #####
56
before the loop
after the loop
---> ###...
11
before the loop
after the loop
---> #
56
before the loop
after the loop
---> .#####
210
before the loop
after the loop
---> ...#......

### Expected Output
3 3
3 3
4 2
1 1
3 4
2 4

### Difference
--- /dev/fd/63	2024-08-16 19:10:19.940231374 +0530
+++ /dev/fd/62	2024-08-16 19:10:19.945231805 +0530
@@ -1,6 +1,24 @@
-3 3
-3 3
-4 2
-1 1
-3 4
-2 4
+55
+before the loop
+after the loop
+---> ..#..
+55
+before the loop
+after the loop
+---> #####
+56
+before the loop
+after the loop
+---> ###...
+11
+before the loop
+after the loop
+---> #
+56
+before the loop
+after the loop
+---> .#####
+210
+before the loop
+after the loop
+---> ...#......

## Test case #2

### Status
<span style="color:red; font-weight:bold; font-size:larger;">Failed</span>

### Input
6
5 5
.....
.....
..#..
.....
.....
5 5
..#..
.###.
#####
.###.
..#..
5 6
......
......
.#....
###...
.#....
1 1
#
5 6
...#..
..###.
.#####
..###.
...#..
2 10
..........
...#......


### Output
55
before the loop
after the loop
---> ..#..
55
before the loop
after the loop
---> #####
56
before the loop
after the loop
---> ###...
11
before the loop
after the loop
---> #
56
before the loop
after the loop
---> .#####
210
before the loop
after the loop
---> ...#......

### Expected Output
3 3
3 3
4 2
1 1
3 4
2 4

### Difference
--- /dev/fd/63	2024-08-16 19:10:20.005236981 +0530
+++ /dev/fd/62	2024-08-16 19:10:20.006237068 +0530
@@ -1,6 +1,24 @@
-3 3
-3 3
-4 2
-1 1
-3 4
-2 4
+55
+before the loop
+after the loop
+---> ..#..
+55
+before the loop
+after the loop
+---> #####
+56
+before the loop
+after the loop
+---> ###...
+11
+before the loop
+after the loop
+---> #
+56
+before the loop
+after the loop
+---> .#####
+210
+before the loop
+after the loop
+---> ...#......

