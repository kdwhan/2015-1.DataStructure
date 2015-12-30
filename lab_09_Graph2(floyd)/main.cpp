// Lab 009 
// Name :
// Student ID :

#include "lab009.h"
#include "lab.hpp"

Graph::Graph()
{ // Graph constructor. 
	numofnodes = 0;
}

void Graph::Init(int n)
{ 
	// initialize the Cost Adjacency Matrix Cost
	numofnodes = n;

	for(int i = 0; i < numofnodes; i++)
	{
		// initialize the adjacency matrix
		for(int j = 0; j < numofnodes; j++)
			Cost[i][j] = LARGECOST;	
		Cost[i][i] = 0;	// cost 0 to itself
	}
}


int main()
{
	Graph g;	// graph 

	while(1)
	{
		cerr << "Graph > ";
		string command;
		cin >> command;

		if(command.compare("quit") == 0)
		{
			break;
		}
		else if(command.compare( "init") == 0)
		{
			int nn;
			cin >> nn;
			g.Init(nn);
		}
		else if(command.compare( "edge") == 0)
		{
			int v1, v2, cost;
			cin >> v1 >> v2 >> cost;
			g.Edge(v1, v2, cost);
		}
		else if(command.compare( "floyd") == 0)
		{
			g.Floyd();
		}
		else if(command.compare( "outpath") == 0)
		{
			int v1, v2;
			cin >> v1 >> v2;
			cout << "Path from " << v1 << " " << v2 << " : ";
			cout << v1 ;
			g.outputPath(v1, v2);
			cout << " => " << g.GetPathLength(v1, v2);
			cout << endl;
		}
	}
	cerr << endl;

	return 1;
}


