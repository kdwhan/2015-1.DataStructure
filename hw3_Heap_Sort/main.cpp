// Homework 3
// Name :
// Student ID :

#include "hw3.h"
#include "lab.hpp"

int main()
{
	HeapSort<int> hsort(256);	// heap sort instance
	string command;

	while(1)
	{
		cerr << "HeapSort > ";
		cin >> command;

		if(command.compare("quit") == 0)
		{
			break;
		}
		else if(command.compare("init") == 0)
		{
			int intarr[1024];
			int i = 1;
			int item;
			while(1)
			{
				cin >> item;
				if(item == -1)
					break;
				intarr[i++] = item;
			}
			hsort.Init(intarr, i - 1);
		}
		else if(command.compare("sort") == 0)
		{
			hsort.Sort();
		}
		
		// show the array
		hsort.ShowArray();
	}
	cerr << endl;

	return 1;
}


