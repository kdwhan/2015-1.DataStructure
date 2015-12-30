
#include "lab006.h"
#include "lab.hpp"

int main()
{
	ArrayTree<int> atree(256);	// sorted list one

	while(true) {
		cerr << "Tree > ";
		string command;
		cin >> command;

		if(command.compare("quit") == 0) {
			break;
		} else if(command.compare("init") == 0) {
			int intarr[1024];
			int i = 1;
			int item;
			while(true) {
				cin >> item;
				if(item == -1)
					break;
				intarr[i++] = item;
			}
			atree.Init(intarr, i - 1);
		} else if(command.compare("pre") == 0) {
			int index;
			cin >> index;
			atree.PreOrder(index);
			cout << endl;
		} else if(command.compare("in") == 0) {
			int index;
			cin >> index;
			atree.InOrder(index);
			cout << endl;
		} else if(command.compare("post") == 0) {
			int index;
			cin >> index;
			atree.PostOrder(index);
			cout << endl;
		}

		// show the current list
		atree.Show();
	}
	cerr << endl;

	return 1;
}

