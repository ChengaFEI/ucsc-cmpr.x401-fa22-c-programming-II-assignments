//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 2: Data Structures and Graphs
// Part 2
// Problem 1
//
// adjacent-matrix-generator.c
// adjacent-matrix-generator
// 
// Function: Generate the adjacency matrix for a given graph (directed/undirected).
// 

#include <stdlib.h>
#include <stdio.h>

#define MATRIX_MAX_SIZE 100
/*-----------------------------------------------------------------------------*/

void generateAdjMatrix(int numVert, int numConn, int arr[numConn][2], int matrix[numVert][numVert], int directed);
/*-----------------------------------------------------------------------------*/

int main(void)
{
  printf("\n");
  
  printf("Test case 1\n"); 
  // Connection array.
  int arr1[2][2] = {{1, 2}, {2, 3}}; 
  printf("----------------\n");
  printf("Expected output:\n"); 
  printf("0 1 0\n"); 
  printf("0 0 1\n"); 
  printf("0 0 0\n"); 
  printf("----------------\n");
  printf("Actual output:\n");  
  // Adjacency matrix.
  int matrix1[3][3]; 
  generateAdjMatrix(3, 2, arr1, matrix1, 1);
  printf("\n");

  printf("Test case 2\n"); 
  // Connection array.
  int arr2[4][2] = {{1, 1}, {1, 3}, {2, 3}, {3, 1}};
  printf("----------------\n");
  printf("Expected output:\n"); 
  printf("1 0 1\n"); 
  printf("0 0 1\n"); 
  printf("1 0 0\n"); 
  printf("----------------\n");
  printf("Actual output:\n"); 
  // Adjacency matrix. 
  int matrix2[3][3];
  generateAdjMatrix(3, 4, arr2, matrix2, 1);
  printf("\n");

  printf("Test case 3\n"); 
  // Connection array.
  int arr3[4][2] = {{1, 2}, {2, 4}, {4, 3}, {4, 4}};
  printf("----------------\n");
  printf("Expected output:\n"); 
  printf("0 1 0 0\n"); 
  printf("0 0 0 1\n"); 
  printf("0 0 0 0\n"); 
  printf("0 0 1 1\n"); 
  printf("----------------\n");
  printf("Actual output:\n"); 
  // Adjacency matrix. 
  int matrix3[4][4];
  generateAdjMatrix(4, 4, arr3, matrix3, 1);
  printf("\n");

  printf("Test case 4\n"); 
  // Connection array.
  int arr4[2][2] = {{1, 2}, {2, 3}}; 
  printf("----------------\n");
  printf("Expected output:\n"); 
  printf("0 1 0\n"); 
  printf("1 0 1\n"); 
  printf("0 1 0\n"); 
  printf("----------------\n");
  printf("Actual output:\n");  
  // Adjacency matrix.
  int matrix4[3][3]; 
  generateAdjMatrix(3, 2, arr4, matrix4, 0);
  printf("\n");

  printf("Test case 5\n"); 
  // Connection array.
  int arr5[4][2] = {{1, 1}, {3, 3}, {2, 3}, {3, 1}};
  printf("----------------\n");
  printf("Expected output:\n"); 
  printf("1 0 1\n"); 
  printf("0 0 1\n"); 
  printf("1 1 1\n"); 
  printf("----------------\n");
  printf("Actual output:\n"); 
  // Adjacency matrix. 
  int matrix5[3][3];
  generateAdjMatrix(3, 4, arr5, matrix5, 0);
  printf("\n");

  printf("Test case 6\n"); 
  // Connection array.
  int arr6[4][2] = {{1, 2}, {2, 4}, {4, 3}, {4, 4}};
  printf("----------------\n");
  printf("Expected output:\n"); 
  printf("0 1 0 0\n"); 
  printf("1 0 0 1\n"); 
  printf("0 0 0 1\n"); 
  printf("0 1 1 1\n"); 
  printf("----------------\n");
  printf("Actual output:\n"); 
  // Adjacency matrix. 
  int matrix6[4][4];
  generateAdjMatrix(4, 4, arr6, matrix6, 0);
  printf("\n");

  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// generateAdjMatrix() generates the adjacency matrix for the graph described by the connection array and displays the matrix on the console.
// @Param:   numVert  -- the number of vertices in the graph.
// @Param:   numConn  -- the number of connections in the connection array.
// @Param:   arr      -- the 2D array with all the connected pairs in the graph.
// @Param:   matrix   -- the adjacency matrix
// @Param:   directed -- 1 indicates a directed graph
//                    -- 0 indicates an undirected graph
// @Return:  matrix
// @Require: none
// @Note:    none
void generateAdjMatrix(int numVert, int numConn, int arr[numConn][2], int matrix[numVert][numVert], int directed)
{
  // Basic variables.
  int src;  // The index of the source vertice.
  int dest; // The index of the destination vertice.

  // Initialize the adjacency matrix to 0s.
  for (int i = 0; i < numVert; i++) {
    for (int j = 0; j < numVert; j++) {
      matrix[i][j] = 0;
    }
  }

  // Store the graph in the adjacency matrix.
  for (int i = 0; i < numConn; i++) {
    // Retrieve the source-destination pair.
    src = arr[i][0];
    dest = arr[i][1];
    // Store the connection in the adjacency matrix.
    matrix[src-1][dest-1] = 1;
    // Add the reverse edge for the undirected graph.
    if (0 == directed) matrix[dest-1][src-1] = 1;
  }

  // Display the adjacency matrix.
  for (int i = 0; i < numVert; i++) {
    for (int j = 0; j < numVert; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}
/*-----------------------------------------------------------------------------*/
