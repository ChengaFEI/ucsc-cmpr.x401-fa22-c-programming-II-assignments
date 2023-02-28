// C++ program to implement adjacency list for directed and undirected graphs
// adjacency list node

#include "Graph.h"

Graph * createGraph(int numVertices, enum GraphType graph_type) {
	Graph *graph = (Graph *) calloc(sizeof(Graph), 1);
	if (graph == NULL) {
		printf ("Error could not allocate memory to create graph");
		exit (-1);
	}
	graph->numberOfVertices = numVertices;
	graph->type = graph_type;
	graph->array = calloc( sizeof(struct AdjList),  numVertices);
	for (int i = 0; i < numVertices; i++)
		graph->array[i].head = NULL;

	return graph;
}

// adding an edge (u, v) between vertices u and v
void addNewEdge(Graph *graph, int u, int v, int _weight) {
	// insert a new node with value v at index u of array
	ListNode *newNode1 =  (ListNode *) malloc(sizeof(ListNode));
	if (newNode1 == NULL) {
		printf ("Error could not allocate memory to create node");
		exit (-1);
	}
	newNode1->value = v;
	newNode1->weight = _weight;
	newNode1->next = graph->array[u].head;
	graph->array[u].head = newNode1;

	if (graph->type == UNDIRECTED) {
		// insert a new node with value u at index v of array
		ListNode *newNode2 = (ListNode *) malloc(sizeof(ListNode));
		if (newNode2 == NULL) {
			printf ("Error could not allocate memory to create node");
			exit (-1);
		}
		newNode2->value = u;
		newNode2->weight = _weight;
		newNode2->next = graph->array[v].head;
		graph->array[v].head = newNode2;
	}
}

// retrieve ListNode head at given index from adjacency list
ListNode* getAdjListHead(Graph *graph, int index) {
	return graph->array[index].head;
}

// print out the graph
void printGraph(Graph *graph)
{

	for (int j = 0; j < graph->numberOfVertices; j++) {
		ListNode *start = graph->array[j].head;
		printf( "|  %d  | " , j);
		while (start != NULL) {
			printf("value %d ," , start->value);
			printf("weight %d ,", start->weight);
			start = start->next;
		}
		printf("\n");
	}

}

int getNumberOfVertices(Graph *graph) {
	return graph->numberOfVertices;
}

void deleteGraph(Graph *graph) {
	free(graph->array);
	graph->array = NULL;
}



