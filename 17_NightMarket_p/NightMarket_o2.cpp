// CPP program to implement traveling salesman 
// problem using naive approach. 
#include <bits/stdc++.h> 
using namespace std; 
#define V 4 
const int maxn = 1e9+5;

// implementation of traveling Salesman Problem 
int travllingSalesmanProblem(int graph[][V], int s) 
{ 
	// store all vertex apart from source vertex 
	vector<int> vertex; 
	for (int i = 0; i < V; i++) 
		if (i != s) {
            vertex.push_back(i); 
            // cout << "i=" << i << ", ";
        }

	// store minimum weight Hamiltonian Cycle. 
	int min_path = INT_MAX; 
	do { 

		// store current Path weight(cost) 
		int current_pathweight = 0; 
		
		// compute current path weight 
		int k = s; 
		for (int i = 0; i < vertex.size(); i++) { 
			current_pathweight += graph[k][vertex[i]]; 
			k = vertex[i]; 
		} 
		current_pathweight += graph[k][s]; 

		// update minimum 
		min_path = min(min_path, current_pathweight); 
		
	} while (next_permutation(vertex.begin(), vertex.end())); 

	return min_path; 
} 

// driver program to test above function 
int main() 
{ 
	// matrix representation of graph 
	int graph[][V] = { { 0, 1, 1, 2 }, 
					{ 1, 0, INT_MAX, INT_MAX }, 
					{ 1, INT_MAX, 0, INT_MAX }, 
					{ 2, INT_MAX, INT_MAX, 0 } }; 
    // int graph[][V] = { { 0, 1, 1, 2 }, 
	// 				{ 1, 0, 0, 0 }, 
	// 				{ 1, 0, 0, 0 }, 
	// 				{ 2, 0, 0, 0 } }; 
	int s = 0; 
	cout << travllingSalesmanProblem(graph, s) << endl; 
	return 0; 
} 
