// UCSC Silicon Valley Extension
// Advanced C Programming
// Extra Credit Assignment
//
// top-flight
// top-flight.c
//
// Function: Schedule the best desired flight path.
//
// Author: Cheng Fei
// Date: 12/31/2022

#include <stdlib.h>
#include <stdio.h>

#include "topflight.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions.
/*-----------------------------------------------------------------------------*/

/// @brief   Find the lowest cost path in the flight graph.
/// @param   graph  -- pointer to the graph to search for the lowest cost path.
/// @param   cost   -- pointer to the cost along the lowest cost path.
/// @param   lcPath -- the lowest cost path, each location in the array indicating the current node's parent node.
/// @return  cost, lcPath
/// @note    graph shouldn't be NULL.
ProcStat findLCPath(Graph *graph, int *cost, int *lcPath)
{
  // Error 1: graph is NULL.
  if (graph == NULL) return NULL_OBJECT;

  // Basic variables.
  int numVert = graph->numVert;
  bool visited[numVert];   // true if the vertex is visited, false if not.
  int minCost[numVert];    // The minimum cost from the origin to each vertex.
  int parentVert[numVert]; // Each vertex's parent vertex in the shortest path tree.
  // Initialize basic variables.
  int origVert = graph->origVert;
  resetSPTArray(numVert, origVert, visited, minCost, parentVert);

  // Search for the lowest cost path using Dijkstra's algorithm (Shortest Path Tree Algorithm).
  int currVert, currCost, currWeight;
  int **matrix = graph->matrix; // Adjacency matrix.
  for (int verti = 0; verti < numVert; verti++) {
    // Take the vertex with the minimum cost.
    currVert = findMinVert(visited, minCost, numVert);
    visited[currVert] = true;
    // Traverse all its adjacent vertices.
    for (int coli = 0; coli < numVert; coli++) {
      currWeight = matrix[currVert][coli];
      // Update the minimum cost of vertices linked to currVert.
      if (currWeight != 0) {
        currCost = minCost[currVert] + currWeight;
        if (currCost <= minCost[coli]) {
          minCost[coli] = currCost;
          parentVert[coli] = currVert;
        }
      }
    }
  }

  // Return the minimum cost for the destination vertex and the path.
  int destVert = graph->destVert;
  *cost = minCost[destVert]; // Lowest cost for the destination vertex.
  for (int verti = 0; verti < numVert; verti++) {
    lcPath[verti] = parentVert[verti]; // Lowest cost path.
  }

  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Find the lowest cost path passing the transit vertex in the flight graph.
/// @param   graph   -- pointer to the graph to search for the lowest cost path.
/// @param   cost    -- pointer to the cost along the lowest cost path.
/// @param   lcPath1 -- the lowest cost path from origVert to tranVert, each location in the array indicating the current node's parent node.
/// @param   lcPath2 -- the lowest cost path from tranVert to destVert, each location in the array indicating the current node's parent node.
/// @return  cost, lcPath1, lcPath2
/// @note    graph shouldn't be NULL.
ProcStat findLCPathWithTranVert(Graph *graph, int *cost, int *lcPath1, int *lcPath2)
{
  // Error 1: graph is NULL.
  if (graph == NULL) return NULL_OBJECT;

  // Basic variables.
  int numVert = graph->numVert;
  bool visited[numVert];   // true if the vertex is visited, false if not.
  int minCost[numVert];    // The minimum cost from the origin to each vertex.
  int parentVert[numVert]; // Each vertex's parent vertex in the shortest path tree.

  // Part 1: Search from the origVert to the tranVert.
  // Initialize basic variables.
  int origVert = graph->origVert;
  resetSPTArray(numVert, origVert, visited, minCost, parentVert);

  // Search for the lowest cost path using Dijkstra's algorithm (Shortest Path Tree Algorithm).
  int currVert, currCost, currWeight;
  int **matrix = graph->matrix; // Adjacency matrix.
  for (int verti = 0; verti < numVert; verti++) {
    // Take the vertex with the minimum cost.
    currVert = findMinVert(visited, minCost, numVert);
    visited[currVert] = true;
    // Traverse all its adjacent vertices.
    for (int coli = 0; coli < numVert; coli++) {
      currWeight = matrix[currVert][coli];
      // Update the minimum cost of vertices linked to currVert.
      if (currWeight != 0) {
        currCost = minCost[currVert] + currWeight;
        if (currCost <= minCost[coli]) {
          minCost[coli] = currCost;
          parentVert[coli] = currVert;
        }
      }
    }
  }

  // Return the minimum cost for the transit vertex and the path.
  int tranVert = graph->tranVert;
  int cost1 = minCost[tranVert]; // Lowest cost for the transit vertex.
  for (int verti = 0; verti < numVert; verti++) {
    lcPath1[verti] = parentVert[verti]; // Lowest cost path.
  }

  // Part 2: Search from the tranVert to the destVert.
  // Initialize basic variables.
  resetSPTArray(numVert, tranVert, visited, minCost, parentVert);

  // Search for the lowest cost path using Dijkstra's algorithm (Shortest Path Tree Algorithm).
  for (int verti = 0; verti < numVert; verti++) {
    // Take the vertex with the minimum cost.
    currVert = findMinVert(visited, minCost, numVert);
    visited[currVert] = true;
    // Traverse all its adjacent vertices.
    for (int coli = 0; coli < numVert; coli++) {
      currWeight = matrix[currVert][coli];
      // Update the minimum cost of vertices linked to currVert.
      if (currWeight != 0) {
        currCost = minCost[currVert] + currWeight;
        if (currCost <= minCost[coli]) {
          minCost[coli] = currCost;
          parentVert[coli] = currVert;
        }
      }
    }
  }

  // Return the minimum cost for the destVert vertex and the path.
  int destVert = graph->destVert;
  int cost2 = minCost[destVert]; // Lowest cost for the transit vertex.
  for (int verti = 0; verti < numVert; verti++) {
    lcPath2[verti] = parentVert[verti]; // Lowest cost path.
  }  

  *cost = cost1 + cost2;

  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Find the lowest cost path in the flight graph.
/// @param   graph      -- pointer to the graph to search for the lowest cost path.
/// @param   cost       -- pointer to the cost along the lowest cost path.
/// @param   lcPath     -- the lowest cost path, each location in the array indicating the current node's parent node.
/// @param   numLayover -- the number of minimum layovers for each vertex. 
/// @return  cost, lcPath, numLayover
/// @note    graph shouldn't be NULL.
ProcStat findLCPathWithMinLayover(Graph *graph, int *cost, int *lcPath, int *numLayover)
{
  // Error 1: graph is NULL.
  if (graph == NULL) return NULL_OBJECT;

  // Basic variables.
  int numVert = graph->numVert;
  bool visited[numVert];   // true if the vertex is visited, false if not.
  int minCost[numVert];    // The minimum cost from the origin to each vertex.
  int parentVert[numVert]; // Each vertex's parent vertex in the shortest path tree.
  int layover[numVert]; // Each vertex's minimum number of layovers from the origin to itself.
  // Initialize basic variables.
  for (int verti = 0; verti < numVert; verti++) {
    visited[verti] = false;     // Default to not visited.
    minCost[verti] = INT32_MAX; // Default to largest number.
    parentVert[verti] = -1;     // Default to no parent node.
    layover[verti] = 0;      // Default to no layovers.
  }
  int origVert = graph->origVert;
  minCost[origVert] = 0;        // Cost for the origin to itself is 0.

  // Search for the lowest cost path using Dijkstra's algorithm (Shortest Path Tree Algorithm).
  int currVert, currCost, currWeight;
  int **matrix = graph->matrix; // Adjacency matrix.
  for (int verti = 0; verti < numVert; verti++) {
    // Take the vertex with the minimum cost.
    currVert = findMinVert(visited, minCost, numVert);
    visited[currVert] = true;
    // Traverse all its adjacent vertices.
    for (int coli = 0; coli < numVert; coli++) {
      currWeight = matrix[currVert][coli];
      // Update the minimum cost of vertices linked to currVert.
      if (currWeight != 0) {
        currCost = minCost[currVert] + currWeight;
        // If the current cost is lower than the previous cost.
        if (currCost < minCost[coli]) {
          minCost[coli] = currCost;
          parentVert[coli] = currVert;
          layover[coli] = layover[currVert] + 1;
        }
        // If the cost is equal, but current path has fewer layovers.
        if (currCost==minCost[coli] && layover[currVert]<layover[coli]) {
          minCost[coli] = currCost;
          parentVert[coli] = currVert;
          layover[coli] = layover[currVert] + 1;
        }
      }
    }
  }

  // Return the minimum cost for the destination vertex and the path.
  int destVert = graph->destVert;
  *cost = minCost[destVert]; // Lowest cost for the destination vertex.
  for (int verti = 0; verti < numVert; verti++) {
    lcPath[verti] = parentVert[verti];  // Lowest cost path.
    numLayover[verti] = layover[verti]; // Number of layovers.
  }

  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Find the lowest cost paths for all the graphs and display the results.
/// @param   graphList -- pointer to the list of all Graph objects.
/// @param   path      -- the output file's path.
/// @return  none
/// @note    graphList shouldn't be NULL.
ProcStat findLCPaths(GraphList *graphList, char *path)
{
  // Error 1: graphList is NULL.
  if (graphList == NULL) return NULL_OBJECT;
  Graph **graphs = graphList->graphs;
  if (graphs == NULL) return NULL_OBJECT;

  // Open the output file's stream.
  FILE *file = fopen(path, "w");
  if (file == NULL) return FILE_NOT_EXIST;

  int numGraph = graphList->numGraph;
  Graph *currGraph;
  int cost;
  fprintf(file, "Finding the lowest cost path......\n");
  fprintf(file, "----------------------------------\n\n");
  // Traverse all the graphs.
  for (int graphi = 0; graphi < numGraph; graphi++) {
    if ((currGraph = graphs[graphi]) != NULL) {
      int numVert = currGraph->numVert;
      int lcPath[numVert]; // Reset the lowest cost path.
      if (findLCPath(currGraph, &cost, lcPath) == SUCCESS) {
        int destVert = currGraph->destVert;
        int origVert = currGraph->origVert;
        fprintf(file, "Graph %d:\n", graphi+1);
        fprintf(file, "The lowest cost path: ");
        // Display the lowest cost path.
        int currVert = destVert;
        fprintf(file, "(destination) ");
        while (lcPath[currVert] != -1) {
          fprintf(file, "%d <- ", currVert);
          currVert = lcPath[currVert];
        }
        if (currVert == origVert) {
          fprintf(file, "%d (origin)\n", currVert);
          fprintf(file, "The lowest cost: %d\n", cost);
        }
        else fprintf(file, "No path found (origin)\n");
      }
    }
    fprintf(file, "\n");
  }

  // Close the output file's stream.
  fclose(file);

  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Find the lowest cost paths passing the transit vertex for all the graphs and display the results.
/// @param   graphList -- pointer to the list of all Graph objects.
/// @param   path      -- the output file's path.
/// @return  none
/// @note    graphList shouldn't be NULL.
ProcStat findLCPathsWithTranVert(GraphList *graphList, char *path)
{
  // Error 1: graphList is NULL.
  if (graphList == NULL) return NULL_OBJECT;
  Graph **graphs = graphList->graphs;
  if (graphs == NULL) return NULL_OBJECT;

  // Open the output file's stream.
  FILE *file = fopen(path, "w");
  if (file == NULL) return FILE_NOT_EXIST;

  int numGraph = graphList->numGraph;
  Graph *currGraph;
  int cost;
  fprintf(file, "Finding the lowest cost path passing the transit vertex......\n");
  fprintf(file, "-------------------------------------------------------------\n\n");
  // Traverse all the graphs.
  for (int graphi = 0; graphi < numGraph; graphi++) {
    if ((currGraph = graphs[graphi]) != NULL) {
      int numVert = currGraph->numVert;
      int lcPath1[numVert]; // Reset the lowest cost path from the origVert to the tranVert.
      int lcPath2[numVert]; // Reset the lowest cost path from the tranVert to the destVert.
      if (findLCPathWithTranVert(currGraph, &cost, lcPath1, lcPath2) == SUCCESS) {
        int destVert = currGraph->destVert;
        int tranVert = currGraph->tranVert;
        int origVert = currGraph->origVert;
        fprintf(file, "Graph %d:\n", graphi+1);
        fprintf(file, "The lowest cost path: ");
        // Display the lowest cost path.
        int currVert = destVert;
        fprintf(file, "(destination) ");
        while (lcPath2[currVert] != -1) {
          fprintf(file, "%d <- ", currVert);
          currVert = lcPath2[currVert];
        }
        if (currVert != tranVert) fprintf(file, "No path found (origin)\n");
        else {
          while (lcPath1[currVert] != -1) {
            fprintf(file, "%d <- ", currVert);
            currVert = lcPath1[currVert];
          }
          if (currVert == origVert) {
            fprintf(file, "%d (origin)\n", currVert);
            fprintf(file, "The lowest cost: %d\n", cost);
          }
          else fprintf(file, "No path found (origin)\n");
        }
      }
    }
    fprintf(file, "\n");
  }

  // Close the output file's stream.
  fclose(file);

  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Find the lowest cost paths with the miminum layovers for all the graphs and display the results.
/// @param   graphList -- pointer to the list of all Graph objects.
/// @param   path      -- the output file's path.
/// @return  none
/// @note    graphList shouldn't be NULL.
ProcStat findLCPathsWithMinLayover(GraphList *graphList, char *path) 
{
  // Error 1: graphList is NULL.
  if (graphList == NULL) return NULL_OBJECT;
  Graph **graphs = graphList->graphs;
  if (graphs == NULL) return NULL_OBJECT;

  // Open the output file's stream.
  FILE *file = fopen(path, "w");
  if (file == NULL) return FILE_NOT_EXIST;

  int numGraph = graphList->numGraph;
  Graph *currGraph;
  int cost;
  fprintf(file, "Finding the lowest cost path with minimum layovers......\n");
  fprintf(file, "--------------------------------------------------------\n\n");
  // Traverse all the graphs.
  for (int graphi = 0; graphi < numGraph; graphi++) {
    if ((currGraph = graphs[graphi]) != NULL) {
      int numVert = currGraph->numVert;
      int lcPath[numVert];     // Reset the lowest cost path.
      int numLayover[numVert]; // Reset the number of layovers.
      if (findLCPathWithMinLayover(currGraph, &cost, lcPath, numLayover) == SUCCESS) {
        int destVert = currGraph->destVert;
        int origVert = currGraph->origVert;
        fprintf(file, "Graph %d:\n", graphi+1);
        fprintf(file, "The lowest cost path: ");
        // Display the lowest cost path.
        int currVert = destVert;
        fprintf(file, "(destination) ");
        while (lcPath[currVert] != -1) {
          fprintf(file, "%d <- ", currVert);
          currVert = lcPath[currVert];
        }
        if (currVert == origVert) {
          fprintf(file, "%d (origin)\n", currVert);
          fprintf(file, "The lowest cost: %d\n", cost);
          fprintf(file, "The number of layovers: %d\n", numLayover[destVert]);
        }
        else fprintf(file, "No path found (origin)\n");
      }
    }
    fprintf(file, "\n");
  }

  // Close the output file's stream.
  fclose(file);

  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Minor functions.
/*-----------------------------------------------------------------------------*/

/// @brief   Find the vertex with the lowest cost that hasn't been visited.
/// @param   visited -- array of boolean values indicating whether the vertex is visited.
/// @param   minCost -- array of minimum costs the vertex takes to go to the origin vertex.
/// @return  the vertex's index.
/// @note    none
int findMinVert(bool *visited, int *minCost, int numVert)
{
  int vert = 0, cost = INT32_MAX;
  for (int verti = 0; verti < numVert; verti++) {
    if (visited[verti]==false && minCost[verti]<cost) {
      vert = verti;
      cost = minCost[verti];
    }
  }
  return vert;
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Helper functions.
/*-----------------------------------------------------------------------------*/

/// @brief   Reset basic arrays used in the SPT algorithm.
/// @param   numVert    -- the total number of vertices.
/// @param   origVert   -- the index of the origin vertex.
/// @param   visited    -- the array of vertices' visited status.
/// @param   minCost    -- the minimum cost of each vertex.
/// @param   parentVert -- the parent vertex of each vertex.
/// @return  visited, minCost, parentVert (updated)
/// @note    none
void resetSPTArray(int numVert, int origVert, bool visited[numVert], int minCost[numVert], int parentVert[numVert])
{
  for (int verti = 0; verti < numVert; verti++) {
    visited[verti] = false;     // Default to not visited.
    minCost[verti] = INT16_MAX; // Default to largest number.
    parentVert[verti] = -1;     // Default to no parent node.
  }
  minCost[origVert] = 0;        // Cost for the origin to itself is 0.
}
/*-----------------------------------------------------------------------------*/