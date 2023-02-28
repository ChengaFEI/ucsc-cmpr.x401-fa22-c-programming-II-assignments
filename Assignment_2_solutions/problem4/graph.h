#ifndef GRAPH_H_
#define GRAPH_H_
#include <stdio.h>
#include <stdlib.h>

enum graphType {DIRECTED, UNDIRECTED};

// graph
typedef struct Graph_t {

	int numberOfVertices;
	int *adjacencyMatrix; // 1-D array to implement 2-D matrix that stores the graph
	enum graphType type;          // may be directed or undirected
} Graph;

Graph *createGraph(int numVertices,  enum graphType graph_type);
void addNewEdge(int u, int v, Graph *graph);
void printGraph(Graph *graph);
int getNumberOfVertices(Graph *graph) ;
int getAdjacencyMatrixValue(int i, int j, Graph *graph);
void setAdjacencyMatrixValue(int i, int j, int value, Graph *graph);
void deleteGraph(Graph *graph);

#endif /* GRAPH_H_ */
