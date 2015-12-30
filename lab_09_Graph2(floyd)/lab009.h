// Lab 009 
// Name :
// Student ID :

#include<iostream>
#include<string>
using namespace std;

#define LARGECOST (99999)

// ---------- Graph class -------------
class Graph
{
public :
	Graph();	// constructor

	void Init(int);
	int GetPathLength(int i, int j) { return c[i][j]; };

	void Edge(int, int, int);
	void Floyd();
	void outputPath(int i, int j);

private :
	int numofnodes;
	int Cost[256][256]; // matrix : 2 dimensional array

	// for the Floyd Algorithm
	// assume that numofnodes <= 256
	int c[256][256]; // shortest path distances
	int kay[256][256]; // largest intermediate nodes
};

