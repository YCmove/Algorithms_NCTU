// C / C++ program for Dijkstra's shortest path algorithm for adjacency 
// list representation of graph 
#include <bits/stdc++.h> 
#include "binary_heap.cpp"
#include "fibonacci_heap.cpp"
using namespace std; 

// A structure to represent a node in adjacency list 
struct AdjListNode 
{ 
	int dest; 
	int weight; 
	struct AdjListNode* next; 
}; 

// A structure to represent an adjacency liat 
struct AdjList 
{ 
	struct AdjListNode *head; // pointer to head node of list 
}; 

// A structure to represent a graph. A graph is an array of adjacency lists. 
// Size of array will be V (number of vertices in graph) 
struct Graph 
{ 
	int V; 
	struct AdjList* array; 
}; 

// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int dest, int weight) 
{ 
	struct AdjListNode* newNode = 
			(struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
	newNode->dest = dest; 
	newNode->weight = weight; 
	newNode->next = NULL; 
	return newNode; 
} 

// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
	graph->V = V; 

	// Create an array of adjacency lists. Size of array will be V 
	graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList)); 

	// Initialize each adjacency list as empty by making head as NULL 
	for (int i = 0; i < V; ++i) 
		graph->array[i].head = NULL; 

	return graph; 
} 

// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest, int weight) 
{ 
	// Add an edge from src to dest. A new node is added to the adjacency 
	// list of src. The node is added at the begining 
	struct AdjListNode* newNode = newAdjListNode(dest, weight); 
	newNode->next = graph->array[src].head; 
	graph->array[src].head = newNode; 

	// Since graph is undirected, add an edge from dest to src also 
	newNode = newAdjListNode(src, weight); 
	newNode->next = graph->array[dest].head; 
	graph->array[dest].head = newNode; 
} 
 

// A utility function used to print the solution 
void printArr(int dist[], int n) 
{ 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < n; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
}


// The main function that calulates distances of shortest paths from src to all 
// vertices. It is a O(ELogV) function 
void dijkstraFibonacciHeap(struct Graph* graph, int src) 
{ 
	int V = graph->V;// Get the number of vertices in graph 
	int dist[V];	 // dist values used to pick minimum weight edge in cut 

	// Initialize min heap with all vertices. dist value of all vertices 
	for (int v = 0; v < V; ++v) 
	{ 
		if(v!=src)
			dist[v] = INT_MAX; 
		else
			dist[v] = 0; 
		insertion(v, dist[v]); 
	} 
int i=0;
	// In the followin loop, min heap contains all nodes 
	// whose shortest distance is not yet finalized. 
	while (no_of_nodes!=0) 
	{ 
		// Extract the vertex with minimum distance value 
		int u = mini->key; // Store the extracted vertex number 
		Extract_min(); 
		
		// Traverse through all adjacent vertices of u (the extracted 
		// vertex) and update their distance values 
		struct AdjListNode* pCrawl = graph->array[u].head; 
		while (pCrawl != NULL) 
		{ 
			int v = pCrawl->dest; 

			// If shortest distance to v is not finalized yet, and distance to v 
			// through u is less than its previously calculated distance 
			if (dist[u] != INT_MAX && 
										pCrawl->weight + dist[u] < dist[v]) 
			{ 
				dist[v] = dist[u] + pCrawl->weight; 

				// update distance value in min heap also 
				Find(mini, v, dist[v]);
			} 
			pCrawl = pCrawl->next; 
		} 
		i++;
		// break;
	} 

	// print the calculated shortest distances 
	printArr(dist, V); 
}


// The main function that calulates distances of shortest paths from src to all 
// vertices. It is a O(ELogV) function 
void dijkstraBinaryHeap(struct Graph* graph, int src) 
{ 
	int V = graph->V;// Get the number of vertices in graph 
	int dist[V];	 // dist values used to pick minimum weight edge in cut 

	// minHeap represents set E 
	struct MinHeap* minHeap = createMinHeap(V); 

	// Initialize min heap with all vertices. dist value of all vertices 
	for (int v = 0; v < V; ++v) 
	{ 
		dist[v] = INT_MAX; 
		minHeap->array[v] = newMinHeapNode(v, dist[v]); 
		minHeap->pos[v] = v; 
	} 

	// Make dist value of src vertex as 0 so that it is extracted first 
	minHeap->array[src] = newMinHeapNode(src, dist[src]); 
	minHeap->pos[src] = src; 
	dist[src] = 0; 
	decreaseKey(minHeap, src, dist[src]); 

	// Initially size of min heap is equal to V 
	minHeap->size = V; 

	// In the followin loop, min heap contains all nodes 
	// whose shortest distance is not yet finalized. 
	while (!isEmpty(minHeap)) 
	{ 
		// Extract the vertex with minimum distance value 
		struct MinHeapNode* minHeapNode = extractMin(minHeap); 
		int u = minHeapNode->v; // Store the extracted vertex number 

		// Traverse through all adjacent vertices of u (the extracted 
		// vertex) and update their distance values 
		struct AdjListNode* pCrawl = graph->array[u].head; 
		while (pCrawl != NULL) 
		{ 
			int v = pCrawl->dest; 

			// If shortest distance to v is not finalized yet, and distance to v 
			// through u is less than its previously calculated distance 
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && 
										pCrawl->weight + dist[u] < dist[v]) 
			{ 
				dist[v] = dist[u] + pCrawl->weight; 

				// update distance value in min heap also 
				decreaseKey(minHeap, v, dist[v]); 
			} 
			pCrawl = pCrawl->next; 
		} 
	} 

	// print the calculated shortest distances 
	printArr(dist, V); 
} 


// Driver program to test above functions 
int main() 
{ 

	// Define the maximum number of vertices of the graph 
	int MAX_VERTICES =50;

	// Define the maximum number of edges 
	int MAX_EDGES =5 ;

	// Define the maximum weight of edges 
	int MAXWEIGHT =200 ;

	struct Graph* graph = createGraph(MAX_VERTICES); 

	set<pair<int, int>> container; 
	set<pair<int, int>>::iterator it; 

	srand(time(NULL)); 

	int NUM; // Number of Vertices 
	int NUMEDGE; // Number of Edges 

	for (int i=1; i<=1; i++) 
	{ 
		NUM = MAX_VERTICES; 

		// Define the maximum number of edges of the graph 
		// Since the most dense graph can have N*(N-1)/2 edges 
		// where N = n number of vertices in the graph 
		NUMEDGE = MAX_EDGES; 


		// First print the number of vertices and edges 
		printf("%d %d\n", NUM, NUMEDGE); 

		// Then print the edges of the form (a b) 
		// where 'a' is connected to 'b' 
		for (int j=1; j<=NUMEDGE; j++) 
		{ 
			int a = rand() % NUM; 
			int b = rand() % NUM; 
			pair<int, int> p = make_pair(a, b); 
			pair<int, int> q = make_pair(b, a); 

			// Search for a random "new" edge every time 
			// Note - In a tree the edge (a, b) is same 
			// as the edge (b, a) 
			while (container.find(p) != container.end()&&container.find(q) != container.end()) 
			{ 
				a = rand() % NUM; 
				b = rand() % NUM; 
				p = make_pair(a, b); 
			} 
			container.insert(p); 
		} 

		for (it=container.begin(); it!=container.end(); ++it) 
		{ 
			int wt = 1 + rand() % MAXWEIGHT; 
			printf("%d %d %d\n", it->first, it->second, wt);
			addEdge(graph,(it->first), (it->second), wt); 
		} 

		container.clear(); 

	} 

	dijkstraFibonacciHeap(graph, 0); 
	// dijkstraBinaryHeap(graph, 0); 

	return 0; 
} 
