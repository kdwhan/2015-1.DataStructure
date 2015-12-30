// Lab 009 
// Name : Kim Dae Whan
// Student ID : 20123338



void Graph::Edge(int v1, int v2, int cost)
{
	//	cerr << "NEED TO IMPLEMENT" << endl;
	Cost[v1][v2] = cost;
	c[v1][v2] = cost;
}

void Graph::Floyd()
{
	for (int i = 0; i<numofnodes; i++)
		for (int j = 0; j<numofnodes; j++)
			c[i][j] = Cost[i][j];

	for (int k = 0; k < numofnodes; k++)
		for (int i = 0; i < numofnodes; i++)
			for (int j = 0; j < numofnodes; j++)
				if (Cost[i][k] + Cost[k][j] < Cost[i][j])
				{
					if (k == 0)
						kay[i][j] = -1;
					else
						kay[i][j] = k;
					Cost[i][j] = Cost[i][k] + Cost[k][j];
					c[i][j] = c[i][k] + c[k][j];
				}
}


void Graph::outputPath(int i, int j)
{ // does not output first vertex (i) on path

	if (i == j)
		return;
	if (kay[i][j] == 0)
	{
		if (j == -1)
			cout << "-" << "0";
		else
			cout << "-" << j;
	}
	else
	{
		outputPath(i, kay[i][j]);
		outputPath(kay[i][j], j);
	}

}



