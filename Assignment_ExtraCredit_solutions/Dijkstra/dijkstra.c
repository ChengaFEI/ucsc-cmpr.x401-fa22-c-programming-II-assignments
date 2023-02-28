
// Author: SPEL Technologies, Inc.
// Implements Dijkstra's algorithm to find the shortest paths in a graph
// MIT License
// Use this for the project
#include "binaryHeap.h"
#include "Graph.h"

// implements dijkstra's algorithm; finds the shortest distances in
void dijkstra(Graph *myGraph, BinaryHeap *heap, bool *known, int *distance, int *path, int numVertices, int s_id) {
	printf("Running Dijkstra's algorithm \n" );

	// set known to false, initialize distance to INT_MAX, path to -1
	for (int i = 0; i < numVertices; i++) {
		known[i] = false;
		distance[i] = INT_MAX;
		path[i] = -1;
	}

	// update the source_id
	distance[s_id] = 0;
	path[s_id] = -1;

	// insert the source vertex into the heap
	/*Node *newnode = (Node *) malloc(sizeof(Node));
	if (newnode == NULL) {
		printf ("Error could not allocate memory to create node");
		exit (-1);
	}
	newnode->value = s_id;
	newnode->distance = distance[s_id];*/

	// insert a node with this distance and id into heap
	insert(heap, distance[s_id], s_id);

	while (!isEmpty(heap)) {
		Node * node = deleteMin(heap);
		int u = node->value; // vertex with minimum distance
		known[u] = true;    // shortest path to u has been found
		free(node);
		node = NULL;

#ifdef DEBUG
		printf("Deleted min key with id %d  and distance %d  from heap\n",  u,  node->distance);
#endif
		// check each vertex v adjacent to u in adjacency list
		ListNode *ptr = getAdjListHead(myGraph, u);
		while (ptr != NULL) {
			int v = ptr->value;

			if (!known[v]) {
#ifdef DEBUG
				printf("Adjacent vertex of node with id %d id %d \n", u, v );
#endif
				if (distance[u]+ ptr->weight < distance[v]) { // update distance[v] if this is shorter
					distance[v] = distance[u] + ptr->weight;
					path[v] = u;
#ifdef DEBUG
					printf("updated distance of %d to %d \n", v, distance[v]);
#endif
					// insert neighbor into heap
					/*Node * newNode = new Node();
					newNode->value = v;
					newNode->distance = distance[v];*/

					insert(heap, distance[v], v);

#ifdef DEBUG
					printf( "Inserted new node into heap %d   %d \n", newNode->value ,  newNode->distance );
					print(heap);
#endif
				}
			}

			ptr = ptr->next;
		}
	}
}


int main()
{

	freopen("data.txt", "r", stdin);
	int vertices, numTestCases;
	enum GraphType type;

	BinaryHeap *binaryHeap = NULL;
	Graph *myGraph = NULL;
	bool *known = NULL;
	int *distance = NULL;
	int *path = NULL;
	char temp[25];
	scanf("%d", &numTestCases); // number of test cases
	scanf("%24s", temp);        // directed or undirected

	if(strcmp(temp, "directed") == 0)
		type = DIRECTED;
	else
		type = UNDIRECTED;

	for (int testi = 1; testi <= numTestCases; testi++) {
		scanf("%d", &vertices);    						// number of vertices in the graph

		int numVertices  = vertices + 1;        // add 1 for the sentinel
		known = (bool *) calloc( sizeof(bool), numVertices);    // known[i] is true if shortest path has been found for vertex i
		distance = (int *) calloc(sizeof(int), numVertices);   // shortest distance of each vertex from the source vertex
		path = (int *) calloc(sizeof(int), numVertices);        // parent of vertex i on shortest path

		// create the heap - make it larger than numVertices because some vertices may be inserted multiple times
		binaryHeap = createBinaryHeap(numVertices*numVertices);

		// create the graph
		myGraph = createGraph(numVertices, type);

		// s_id is the source vertex
		int s_id;
		scanf("%d", &s_id);

		// numEdges is the number of edges
		int numEdges;
		scanf("%d", &numEdges);

		int vertex1, vertex2, weight;

		for (int i = 0; i < numEdges; i++) {
			scanf("%d", &vertex1);
			scanf("%d", &vertex2);
			scanf("%d", &weight);

			addNewEdge(myGraph, vertex1, vertex2, weight);
		}
		printf("\n\n Test case: %d \n", testi);

		printGraph(myGraph);
		dijkstra(myGraph, binaryHeap, known, distance, path, numVertices, s_id);


		for (int i = 0; i < numVertices - 1; i++) {
			printf("id: %d   distance is: %d  path is: %d \n" , i,  distance[i], path[i]);
		}

		free(binaryHeap);
		binaryHeap = NULL;
		free(myGraph);
		myGraph = NULL;
		free(known);
		known = NULL;
		free(distance);
		distance = NULL;
		free(path);
		path = NULL;
	}
	return (EXIT_SUCCESS);
}
