# 323 2-Heap-Sort<br />
CSC 323-32: Project 2 <Heap Sort> (C++/Java)<br />
Preston Peck<br />
Due date: Sept. 20, 2016 <br />

**** Algorithm steps for heap sort:<br />

Step 1: open the input file;<br />
     1.1: read and count the number of date item in the input file<br />
     1.2: close the file<br />
     1.3: dynamically allocate the PQAry of the size count+1<br />
     1.4:  initallize PQAry[0] to 0<br />
Step 2: call buildPQAry<br />
Step 3: call deletePQAry<br />

**** Algorithm steps for buildHeap:<br />

Step 1: open the input file for the second time<br />
Step 2: data <-- get a data item from the input file<br />
Step 3: insertOneDataItem (data)<br />
     3.1: bubbleUp<br />
Step 4: printPQAry (print the content of PQAry up to the first 10 items of the PQAry to *out1file*<br />
Step 5: repeat step 2 - 4 while input file is NOT empty<br />
Step 6: close the input file<br />

**** Algorithm steps for deleteRoot:<br />

Step 1: open the output file<br />
Step 2: deleteRoot <br />
     2.1: print the root to *outfile2*<br />
     2.2: bubbleDown<br />
Step 3: printPQAry (print the content of PQAry up to the first 10 items of the PQAryto *outfile1*<br />
Step 4: repeat step 2 and 3 while PQAry is NOT empty<br />
Step 5: close the two output files<br />


INPUT<br />
23<br />
82 12 53<br />
9 39 2 13<br />
30<br />
61<br />
21<br />
45<br />
18 19 42<br />
53 4 93 34 8 36 37<br />
10 11<br />
7 8<br />
5 10 20<br />

OUTPUT<br />
23 <br />
23 82 <br />
12 82 23 <br />
12 53 23 82 <br />
9 12 23 82 53 <br />
9 12 23 82 53 39 <br />
2 12 9 82 53 39 23 <br />
2 12 9 13 53 39 23 82 <br />
2 12 9 13 53 39 23 82 30 <br />
2 12 9 13 53 39 23 82 30 61 <br />
2 12 9 13 21 39 23 82 30 61 <br />
2 12 9 13 21 39 23 82 30 61 <br />
2 12 9 13 21 18 23 82 30 61 <br />
2 12 9 13 21 18 19 82 30 61 <br />
2 12 9 13 21 18 19 82 30 61 <br />
2 12 9 13 21 18 19 53 30 61 <br />
2 4 9 12 21 18 19 13 30 61 <br />
2 4 9 12 21 18 19 13 30 61 <br />
2 4 9 12 21 18 19 13 30 61 <br />
2 4 9 12 8 18 19 13 30 21 <br />
2 4 9 12 8 18 19 13 30 21 <br />
2 4 9 12 8 18 19 13 30 21 <br />
2 4 9 12 8 18 19 13 30 21 <br />
2 4 9 12 8 11 19 13 30 21 <br />
2 4 7 12 8 9 19 13 30 21 <br />
2 4 7 12 8 8 19 13 30 21 <br />
2 4 5 12 8 7 19 13 30 21 <br />
2 4 5 12 8 7 10 13 30 21 <br />
2 4 5 12 8 7 10 13 30 21 <br />

4 8 5 12 10 7 10 13 30 21 <br />
5 8 7 12 10 8 10 13 30 21 <br />
7 8 8 12 10 9 10 13 30 21 <br />
8 10 8 12 20 9 10 13 30 21 <br />
8 10 9 12 20 11 10 13 30 21 <br />
9 10 10 12 20 11 19 13 30 21 <br />
10 12 10 13 20 11 19 39 30 21 <br />
10 12 11 13 20 18 19 39 30 21 <br />
11 12 18 13 20 23 19 39 30 21 <br />
12 13 18 30 20 23 19 39 34 21 <br />
13 20 18 30 21 23 19 39 34 61 <br />
18 20 19 30 21 23 42 39 34 61 <br />
19 20 23 30 21 36 42 39 34 61 <br />
20 21 23 30 37 36 42 39 34 61 <br />
21 30 23 34 37 36 42 39 93 61 <br />
23 30 36 34 37 45 42 39 93 61 <br />
30 34 36 39 37 45 42 53 93 61 <br />
34 37 36 39 53 45 42 53 93 61 <br />
36 37 42 39 53 45 82 53 93 61 <br />
37 39 42 53 53 45 82 61 93 <br />
39 53 42 53 93 45 82 61 <br />
42 53 45 53 93 61 82 <br />
45 53 82 53 93 61 <br />
53 53 82 61 93 <br />
53 93 82 61 <br />
61 93 82 <br />
82 93 <br />
93<br />

2 4 5 7 8 8 9 10 10 11 12 13 18 19 20 21 23 30 34 36 37 39 42 45 53 53 61 82 93<br />
