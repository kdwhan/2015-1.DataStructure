// Lab 008 
// Name : Kim Dae Whan
// Student ID : 20123338


void Graph::Edge(int e1, int e2)
{
	Adj[e1][e2] = 1;
	Adj[e2][e1] = Adj[e1][e2];
	//	cerr << "NEED TO IMPLEMENT" << endl;

}

void Graph::Dfs(int v)
{
	//	cerr << "NEED TO IMPLEMENT" << endl;
	mark[v] = 1;
	cout << v << " ";

	for (int i = 0; i < numofnodes; i++)
	{
		if (Adj[v][i] == 1 && mark[i] == 0)
			Dfs(i);
	}


}

