/*
 * Graph.h
 *
 *  Created on: Mar 25, 2020
 *      Author: rgrover
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum GraphType {DIRECTED, UNDIRECTED};

// node in the adjacency list
typedef struct ListNode_t
{
	int value;  // node id
	int weight; // weight of adjacent edge
	struct ListNode_t *next; // pointer to next node
} ListNode;


// adjacency list
struct AdjList
{
     ListNode *head;
};

// graph with adjacency list
typedef struct Graph_t {
	int numberOfVertices;
	struct AdjList *array;
	enum GraphType type; // may be directed or undirected
} Graph;

Graph * createGraph(int numVertices, enum GraphType graph_type);
void addNewEdge(Graph *graph, int u, int v, int _weight);
ListNode* getAdjListHead(Graph *graph, int index);
void printGraph(Graph *graph);
void deleteGraph(Graph *graph);
int getNumberOfVertices(Graph *graph);

#endif /* GRAPH_H_ */
