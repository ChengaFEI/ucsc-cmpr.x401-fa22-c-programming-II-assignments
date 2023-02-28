// UCSC Silicon Valley Extension
// Advanced C Programming
// Extra Credit Assignment
//
// top-flight
// graph.c
//
// Object: Graph.
//
// Author: Cheng Fei
// Date: 12/31/2022

#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions.
/*-----------------------------------------------------------------------------*/

/// @brief   Add an edge from fromVert to toVert, with a given weight.
/// @param   graph    -- pointer to the graph to insert the new edge.
/// @param   fromVert -- The starting vertex of the edge.
/// @param   toVert   -- The ending vertex of the edge.
/// @param   weight   -- The weight of the edge.
/// @return  ProcStat -- the process status code.
/// @note    graph shouldn't be NULL.
/// @note    The index of fromVert/toVert shouldn't exceed the bounds.
ProcStat addEdge(Graph *graph, int fromVert, int toVert, int weight)
{
  // Error 1: graph is NULL.
  if (graph == NULL) return NULL_OBJECT;
  // Error 2: the index of fromVert/toVert exceeds the bounds.
  int numVert = graph->numVert;
  if (fromVert<0 || fromVert>=numVert || toVert<0 || toVert>=numVert) 
    return OUT_OF_BOUND;
  
  // Add the edge.
  graph->matrix[fromVert][toVert] = weight;
  // Successful adding an edge.
  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Minor functions.
/*-----------------------------------------------------------------------------*/

/// @brief   Read data from the input file.
/// @param   path -- the path of the input file.
/// @param   graphList -- pointer to the GraphList object.
/// @return  ProcStat  -- the process status code.
/// @note    graphList shouldn't be NULL.
ProcStat readInputs(char *path, GraphList *graphList)
{
  // Error 1: graphList is NULL.
  if (graphList == NULL) return NULL_OBJECT;

  // Step  0: open the input file's stream.
  FILE *file = fopen(path, "r");
  if (file == NULL) return FILE_NOT_EXIST;

  // Step  1: Read the number and type of graphs and initialize graphs.
  fscanf(file, "%d", &(graphList->numGraph));
  fscanf(file, "%s", graphList->type);
  graphList->graphs = (Graph **) malloc(sizeof(Graph *));

  // Step  2: Read graphs.
  int numGraph = graphList->numGraph;
  int numVert, origVert, tranVert, destVert;
  int numEdge, fromVert, toVert, weight;
  Graph *currGraph;
  for (int graphi = 0; graphi < numGraph; graphi++) {
    // 2.1: Read current graph's metadata.
    fscanf(file, "%d ", &numVert);
    fscanf(file, "%d ", &origVert);
    fscanf(file, "%d ", &tranVert);
    fscanf(file, "%d ", &destVert);
    currGraph = (Graph *) malloc(sizeof(Graph));
    if (initGraph(currGraph, numVert, origVert, tranVert, destVert) == SUCCESS)
      // Add the current graph to the graphList if graph is successfully initialized.
      graphList->graphs[graphi] = currGraph;
    // 2.2: Read current graph's edge and weight data.
    fscanf(file, "%d ", &numEdge);
    for (int edgei = 0; edgei < numEdge; edgei++)
    {
      fscanf(file, "%d %d %d ", &fromVert, &toVert, &weight);
      addEdge(currGraph, fromVert, toVert, weight);
    }
  }

  // Step  X: close the input file's stream.
  fclose(file);

  // Successful reading.
  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Initialize the Graph object.
/// @param   graph    -- pointer to the graph to initialize.
/// @param   numVert  -- the total number of vertices in the graph.
/// @param   origVert -- the origin vertex in the graph.
/// @param   tranVert -- the transit vertex in the graph.
/// @param   destVert -- the destination vertex in the graph.
/// @return  ProStat  -- the process status code.
/// @note    graph shouldn't be NULL.
ProcStat initGraph(Graph *graph, int numVert, int origVert, int tranVert, int destVert)
{
  // Error 1: graph is NULL.
  if (graph == NULL) return NULL_OBJECT;

  // Step  1: Initialize number of vertices.
  graph->numVert = numVert;
  graph->origVert = origVert;
  graph->tranVert = tranVert;
  graph->destVert = destVert;

  // Step  2: Initialize the adjacency matrix.
  graph->matrix = (int **) calloc(numVert, sizeof(int *));
  // Error 2: Out of memory.
  if (graph->matrix == NULL) {
    return OUT_OF_MEMORY;
  }
  for (int rowi = 0; rowi < numVert; rowi++) {
    graph->matrix[rowi] = (int *) calloc(numVert, sizeof(int));
    // Error 2: Out of memory.
    if (graph->matrix[rowi] == NULL) {
      freeGraph(graph);
      return OUT_OF_MEMORY;
    }
  }

  // Step  3: Default all weights in the adjacency matrix as 0.
  for (int rowi = 0; rowi < numVert; rowi++) {
    for (int coli = 0; coli < numVert; coli++) {
      graph->matrix[rowi][coli] = 0;
    }
  }

  // Successful initialization.
  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Release all the dynamic memories used by graph.
/// @param   graph    -- pointer to the graph object to be freed.
/// @return  ProcStat -- the process status code.
/// @note    graph shouldn't be NULL.
ProcStat freeGraph(Graph *graph)
{
  // Error 1: graph is NULL.
  if (graph == NULL) return NULL_OBJECT;
  
  // Step  1: Free the adjacency matrix.
  if (graph->matrix != NULL) {
    int numVert = graph->numVert;
    int **matrix = graph->matrix;
    for (int rowi = 0; rowi < numVert; rowi++) {
      if (matrix[rowi] != NULL) free(matrix[rowi]);
    }
  }
  
  // Step  2: Free the graph itself.
  free(graph);

  // Successful freeing.
  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Release all the dynamic memories used by graphList.
/// @param   graphList -- pointer to the GraphList object to be freed.
/// @return  ProcStat  -- the process status code.
/// @note    graphList shouldn't be NULL.
ProcStat freeGraphList(GraphList *graphList)
{
  // Error 1: graphList is NULL.
  if (graphList == NULL) return NULL_OBJECT;

  // Step  1: Free stored graphs.
  Graph *currGraph;
  for (int graphi = 0; graphi < graphList->numGraph; graphi++) {
    currGraph = graphList->graphs[graphi];
    if (currGraph != NULL) freeGraph(currGraph);
  }

  // Step  2: Free the graphList itself.
  free(graphList);

  // Successful freeing.
  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Display the adjacency matrix of the graph.
/// @param   graph    -- pointer to the Graph object to display.
/// @return  ProcStat -- the process status code.
/// @note    graph shouldn't be NULL.
ProcStat printGraph(Graph *graph, FILE *file)
{
  // Error 1: graph is NULL.
  if (graph == NULL) return NULL_OBJECT;
  int **matrix = graph->matrix;
  // Error 2: adjacency matrix is NULL.
  if (matrix == NULL) return NULL_OBJECT;

  int numVert = graph->numVert;
  fprintf(file, "adjacency matrix\n");
  fprintf(file, "------------------\n");
  for (int rowi = 0; rowi < numVert; rowi++) {
    // Error 3: matrix's row is NULL.
    if (matrix[rowi] == NULL) return NULL_OBJECT;
    for (int coli = 0; coli < numVert; coli++) {
      // Display the data.
      fprintf(file, "%d ", matrix[rowi][coli]);
    }
    fprintf(file, "\n");
  }

  // Successful display.
  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Display the adjacency matrix of all the graphs.
/// @param   graphList -- pointer to the GraphList object to be displayed.
/// @return  ProcStat  -- the process status code.
/// @note    graphList shouldn't be NULL.
ProcStat printGraphList(GraphList *graphList, char *path)
{
  // Error 1: graphList is NULL.
  if (graphList == NULL) return NULL_OBJECT;
  Graph **graphs = graphList->graphs;
  if (graphs == NULL) return NULL_OBJECT;

  // Open the output file's stream.
  FILE *file = fopen(path, "w");
  if (file == NULL) return FILE_NOT_EXIST;

  // Display all the graphs.
  int numGraph = graphList->numGraph;
  Graph *currGraph;
  ProcStat stat;
  for (int graphi = 0; graphi < numGraph; graphi++) {
    fprintf(file, "Graph %d:\n", graphi+1);
    currGraph = graphs[graphi];
    if ((stat = printGraph(currGraph, file)) != SUCCESS) return stat;
    fprintf(file, "\n");
  }

  // Close the output file's stream.
  fclose(file);

  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Helper functions.
/*-----------------------------------------------------------------------------*/