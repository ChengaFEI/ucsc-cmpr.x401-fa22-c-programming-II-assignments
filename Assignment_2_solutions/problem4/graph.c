/* Copyright 2017 SPEL Technologies, Inc.
 * A Graph created using an adjacency matrix
 * The adjacency matrix is stored a one-dimensional array of V by V matrices.
 * The value (i, j) which represents if vertex i is adjacent to vertex j in a
 * two-dimensional matrix is converted to the corresponding index in the
 * one-dimensional array using:
 * index = i * number of vertices + j.
 *
 *
 */

#include "graph.h"

Graph *createGraph(int numVertices,  enum graphType graph_type) {

	Graph *graph = (Graph *) calloc(sizeof(Graph), 1);
	if (graph == NULL) {
		printf("%s", "Error: Graph could not be allocated");
		exit (EXIT_FAILURE);
	} else {
		graph->numberOfVertices = numVertices;
		graph->type = graph_type;
		graph->adjacencyMatrix = calloc(sizeof(int[numVertices * numVertices]), 1);

		return graph;
	}
}



// adding an edge (u, v) between vertices u and v
void addNewEdge(int u, int v, Graph *graph) {
	// set adjacencyMatrix[u][v] to 1
	int index = u * graph->numberOfVertices + v;
	graph->adjacencyMatrix[index] = 1;
	if (graph->type == UNDIRECTED) {
		graph->adjacencyMatrix[index] = 1;
	}
}

// print out the graph
void printGraph(Graph *graph)
{
	printf("%s", "Displaying adjacency list of graph ");
	for (int i = 0; i <graph->numberOfVertices; i++) {
		for (int j = 0; j < graph->numberOfVertices; j++) {
			int index = i * graph->numberOfVertices + j;
			printf("%d", graph->adjacencyMatrix[index]);
		}
		printf("\n");
	}
}

int getNumberOfVertices(Graph *graph) {
	return graph->numberOfVertices;
}

int getAdjacencyMatrixValue(int i, int j, Graph *graph) {
	int index = i * graph->numberOfVertices + j;
	return (graph->adjacencyMatrix[index]);
}

void setAdjacencyMatrixValue(int i, int j, int value, Graph *graph) {
	int index = i * graph->numberOfVertices + j;
	graph->adjacencyMatrix[index] = value;
}

void deleteGraph(Graph *graph) {
	if (graph->adjacencyMatrix != NULL) {
		free(graph->adjacencyMatrix);
		graph->adjacencyMatrix= NULL;
	}
}


