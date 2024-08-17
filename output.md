# Test Results - 2024-08-17 13:05:28
## Test case #1

### Status
<span style="color:red; font-weight:bold; font-size:larger;">Failed</span>

### Input
5
1 1 1
5 1 1
5 2 1
5 2 2
5 5 3


### Output
NO
NO
--- diff --- 1
YES
--- diff --- 1
NO
--- diff --- 0
YES

### Expected Output
NO
NO
YES
NO
YES

### Difference
--- /dev/fd/63	2024-08-17 13:05:28.624618010 +0530
+++ /dev/fd/62	2024-08-17 13:05:28.624618010 +0530
@@ -1,5 +1,8 @@
 NO
 NO
+--- diff --- 1
 YES
+--- diff --- 1
 NO
+--- diff --- 0
 YES

## Test case #2

### Status
<span style="color:red; font-weight:bold; font-size:larger;">Failed</span>

### Input
5
1 1 1
5 1 1
5 2 1
5 2 2
5 5 3


### Output
NO
NO
--- diff --- 1
YES
--- diff --- 1
NO
--- diff --- 0
YES

### Expected Output
NO
NO
YES
NO
YES

### Difference
--- /dev/fd/63	2024-08-17 13:05:28.636618363 +0530
+++ /dev/fd/62	2024-08-17 13:05:28.637618393 +0530
@@ -1,5 +1,8 @@
 NO
 NO
+--- diff --- 1
 YES
+--- diff --- 1
 NO
+--- diff --- 0
 YES

