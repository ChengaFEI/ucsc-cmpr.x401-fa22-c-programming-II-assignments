// UCSC Silicon Valley Extension
// Advanced C Programming
// Extra Credit Assignment
//
// top-flight
// graph.h
//
// Object: Graph.
//
// Author: Cheng Fei
// Date: 12/31/2022

#include <stdlib.h>
#include <stdio.h>

#include "procstatus.h"
/*-----------------------------------------------------------------------------*/

// Graph object.
typedef struct {
  int **matrix; // The adjacency matrix. 
  int numVert;  // The total number of vertices.
  int origVert; // The origin vertex.
  int tranVert; // The transit vertex.
  int destVert; // The destination vertex.
} Graph;

// Array of Graph objects.
typedef struct {
  int numGraph;   // The total number of graphs.
  char type[10];  // "directed"/"undirected" graphs.
  Graph **graphs; // The array of graphs.
} GraphList;
/*-----------------------------------------------------------------------------*/

// Major functions.
// Functions in this group perform major functionalities of Graph object.

ProcStat addEdge(Graph *graph, int fromVert, int toVert, int weight);
/*-----------------------------------------------------------------------------*/

// Minor functions.
// Functions in this group perform auxiliary functionalities of Graph object.

// File I/O.
ProcStat readInputs(char *path, GraphList *graphList);
// Manage the memory.
ProcStat initGraph(Graph *graph, int numVert, int origVert, int tranVert, int destVert);
ProcStat freeGraph(Graph *graph);
ProcStat freeGraphList(GraphList *graphList);
// Display data.
ProcStat printGraph(Graph *graph, FILE *file);
ProcStat printGraphList(GraphList *graphList, char *path);
/*-----------------------------------------------------------------------------*/

// Helper functions.
// Functions in this group help with major/minor functions' implementation.

/*-----------------------------------------------------------------------------*/