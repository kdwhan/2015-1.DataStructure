// Lab 008 
// Name :
// Student ID :

#include "lab008.h"
#include "lab.hpp"


int main() {
	Graph graph;	// graph 

	while(true) {
		cerr << "Graph > ";
		string command;
		cin >> command;

		if(command.compare("quit") == 0)
		{
			break;
		}
		else if(command.compare("init") == 0)
		{
			int nn;
			cin >> nn;
			graph.Init(nn);
		}
		else if(command.compare("edge") == 0)
		{
			int e1, e2;
			cin >> e1 >> e2;
			graph.Edge(e1, e2);
		}
		else if(command.compare("dfs") == 0)
		{
			graph.InitVisited();
			int nid;
			cin >> nid;
			graph.Dfs(nid);
			cout << endl;
		}
	}
	cerr << endl;

	return 1;
}
