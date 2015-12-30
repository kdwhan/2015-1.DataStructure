// Lab 008 
// Name :
// Student ID :

#include<iostream>
#include<string>
using namespace std;

// ---------- Graph class -------------
class Graph
{
public :
	Graph();	// constructor

	void Init(int);
	void InitVisited();
	void Edge(int, int);
	void Dfs(int);
private :
	int **Adj; // matrix : 2 dimensional array
	int numofnodes;
	int *mark;
};

Graph::Graph()
{ // Graph constructor. 
	numofnodes = 0;
	Adj = NULL;
	mark = NULL;
}

void Graph::Init(int n)
{ 
	// initialize the Adjacency Matrix Adj
	if(Adj)	
	{	// when there is old Adj, delete it
		for(int i = 0; i < numofnodes; i++)
			delete [] Adj[i];	
		delete Adj;
	}
	numofnodes = n;
	// now create 2 dimensional array of numofnodes * numofnodes
	Adj = new int*[numofnodes];
	for(int i = 0; i < numofnodes; i++)
	{
		Adj[i] = new int[numofnodes];
		// initialize all entries to 0
		for(int j = 0; j < numofnodes; j++)
			Adj[i][j] = 0;	// initialize the adjacency matrix
	}
}

void Graph::InitVisited()
{ // initialize the mark array
	if(mark)
		delete mark;
	mark = new int[numofnodes];
	for(int i = 0; i < numofnodes; i++)
		mark[i] = 0;	// initialize the mark vector
	
}

