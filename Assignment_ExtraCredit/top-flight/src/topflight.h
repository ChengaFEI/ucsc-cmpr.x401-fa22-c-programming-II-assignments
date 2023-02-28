// UCSC Silicon Valley Extension
// Advanced C Programming
// Extra Credit Assignment
//
// top-flight
// top-flight.h
//
// Function: Schedule the best desired flight path.
//
// Author: Cheng Fei
// Date: 12/31/2022

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "graph.h"
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/

// Major functions.
// Functions in this group perform major functionalities of the top-flight program.
ProcStat findLCPath(Graph *graph, int *cost, int *lcPath);
ProcStat findLCPathWithTranVert(Graph *graph, int *cost, int *lcPath1, int *lcPath2);
ProcStat findLCPathWithMinLayover(Graph *graph, int *cost, int *lcPath, int *numLayover);
ProcStat findLCPaths(GraphList *graphList, char *path);
ProcStat findLCPathsWithTranVert(GraphList *graphList, char *path);
ProcStat findLCPathsWithMinLayover(GraphList *graphList, char *path);
/*-----------------------------------------------------------------------------*/

// Minor functions.
// Functions in this group perform auxiliary functionalities of the top-flight program.
int findMinVert(bool *visited, int *minCost, int numVert);
/*-----------------------------------------------------------------------------*/

// Helper functions.
// Functions in this group help with major/minor functions' implementation.
void resetSPTArray(int numVert, int origVert, bool visited[numVert], int minCost[numVert], int parentVert[numVert]);
/*-----------------------------------------------------------------------------*/