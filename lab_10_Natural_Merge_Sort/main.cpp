// Lab 010
// Name :
// Student ID :

#include<iostream>
#include<string>
using namespace std;

#include "lab.hpp"

void ShowArray(string t, int *intarray, int n)
{
	cout << t << " : ";
	for(int i = 0; i < n; i++)
	{
		cout << intarray[i] << " ";
	}
	cout << endl;
}

int main()
{
	int inputArray[256];	// input Array
	int outputArray[256];	// output Array 

	while(1)
	{
		cerr << "Merge > ";
		string command;
		cin >> command;

		if(command.compare("quit") == 0)
		{
			break;
		}
		else if(command.compare("init") == 0)
		{
			int n = 0;
			int item;
			while(true)
			{
				cin >> item;
				if(item == -1)
					break;
				inputArray[n++] = item;
			}
			ShowArray("Input", inputArray, n);

			NaturalMerge(inputArray, n, outputArray);

			ShowArray("Output", outputArray, n);
			cout << endl;
		}
	}
	cerr << endl;

	return 1;
}
