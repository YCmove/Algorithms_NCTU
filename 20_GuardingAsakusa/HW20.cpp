#include <iostream>
using namespace std;

const int INF = 1 << 30;

int main(){

//    minimize the brightness of the brightest roads

	int n, s, q;

	cin>> n >> s >> q;

	int graph[n][n];
    for (int i = 0; i < n; i++) // initialize
    {
		for (int j = 0; j < n; j++)
		{
		    graph[i][j] = INF;
		}
		graph[i][i] = 0;
        // the weight to the same node == 0
	}

    for (int i = 0; i < s; i++)
    {
        int a,b,weight;
        cin >> a >> b >> weight;
        graph[a][b] = min(graph[a][b], weight);
        // the same route with different weight
    }

    for (int k = 0; k < n; k++)
    {
		for(int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{   // the brightest road between i->k & k->j
			    graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
			}   // minimize the brightest road

		}
	}

    for (int i = 0; i < q; i++)
    {
        int a,b;
        cin >> a >> b;
        if (graph[a][b] == INF || graph[b][a] == INF) // not cycle
            cout << "-1" << endl;
        else
            cout << max(graph[b][a], graph[a][b]) << endl;
            // the brightest road between node a & b
    }

	return 0;
}
