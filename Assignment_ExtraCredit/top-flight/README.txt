// UCSC Silicon Valley Extension
// Advanced C Programming
// Extra Credit Assignment
//
// top-flight
// 
// Function: Find the lowest cost path in a flight graph. (For detailed descriptions, please read RAEDME.pdf)



1. Important notice before compiling the program:

The structure of the input file is modified:

10       # number of the test cases
directed # directed graph
5        # number of vertices
5        # starting vertex
1        # transit vertex
0        # destination vertex
9        # number of edges
0 1 6    # edge connects vertices 0 and 1 with weight 6
0 3 8    # edge connects vertices 0 and 3 with weight 8
1 2 4    # edge connects vertices 1 and 2 with weight 4
1 3 1    # edge connects vertices 1 and 3 with weight 1



2. Problem: Determine the recurrence relation for your algorithm in part (c). Solve the recurrence relation and obtain the worst-case running time of your algorithm. Show your work.

Response: 
My algorithm traverses all vertices, and, in each loop, the program traverses all unvisited vertices to find the next adjacent vertex to visit. So the recurrence relation is:
T(V) = V + T(V-1), T(1) = 1  // V is the number of vertices in the graph.
So, we have T(V) = V + (V-1) + (V-2) + ... + 2 + 1 = O(V^2)



3. Problem: Obtain the execution time of your program.

Response: 
(Please refer to your console output for a precise execution time) The approximate time is from 0.0006s to 0.001s.



4. Usage: Please compile all source codes in the "src" folder. The main function lies in the "test.c" file.



5. Files: 
"graph.c" includes the data structure Graph/GraphList to store the graph data.
"Topflight.c" includes the algorithm to find the lowest cost path and its variants.
"Prostates.h" includes an enumeration object to pass the procedure's status outside the procedure and check the called functions status.



6. Test cases:
Test cases are stored in the "test-case" folder. If you want to put them in your own folder, please change the INPUT_FILEPATH, OUTPUT_GRAPH_FILEPATH, OUTPUT_LCP_FILEPATH, OUTPUT_LCP_TRAN_FILEPATH, OUTPUT_LCP_LAYOVER_FILEPATH variables in the "test.c" file accordingly.