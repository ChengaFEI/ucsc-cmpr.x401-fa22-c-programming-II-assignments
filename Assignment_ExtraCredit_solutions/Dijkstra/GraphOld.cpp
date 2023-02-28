// C++ program to implement adjacency list for directed and undirected graphs
// adjacency list node
/*#include <iostream>
#include <string>

using namespace std;

// node in the adjacency list
struct ListNode
{
	int value;  // node id
	int weight; // weight of adjacent edge
	struct ListNode* next; // pointer to next node
};

// adjacency list
struct AdjList
{
	struct ListNode *head;
};

// graph with adjacency list
class Graph {

private:
	int numberOfVertices;
	struct AdjList* array;
	string type; // may be directed or undirected

public:
	Graph(int numVertices, string graph_type) {
		numberOfVertices = numVertices;
		type = graph_type;
		array = new AdjList [numVertices];
		for (int i = 0; i < numVertices; i++)
			array[i].head = NULL;
	}


	// adding an edge (u, v) between vertices u and v
	void addNewEdge(int u, int v, int _weight) {
		// insert a new node with value v at index u of array
		ListNode* newNode1 = new ListNode();
		newNode1->value = v;
		newNode1->weight = _weight;
		newNode1->next = array[u].head;
		array[u].head = newNode1;

		if (type == "undirected") {
			// insert a new node with value u at index v of array
			ListNode* newNode2 = new ListNode();
			newNode2->value = u;
			newNode2->weight = _weight;
			newNode2->next = array[v].head;
			array[v].head = newNode2;
		}
	}

	// retrieve ListNode head at given index from adjacency list
	ListNode* getAdjListHead(int index) {
		return array[index].head;
	}

	// print out the graph
	void print()
	{

		for (int j = 0; j < numberOfVertices; j++) {
			ListNode* start = array[j].head;
			cout << "| " << j << " |" ;
			while (start != NULL) {
				cout << "value" << start->value << ",";
				cout << "weight" << start->weight << ",";
				start = start->next;
		}
			cout << endl;
		}

	}

	int getNumberOfVertices() {
		return numberOfVertices;
	}
};*/
