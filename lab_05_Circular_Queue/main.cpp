
#include "lab005.h"
#include "lab.hpp"

template <class T> 
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	if(capacity < 1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;
}



int main()
{
	Queue<int> q(7);

	while(1)
	{
		cerr << "Queueop > " << endl;
		char command[256];
		cin >> command;
		if(strcmp (command, "quit") == 0)
			break;

		cout << endl << command << " ";
		try {
			if(strcmp (command, "push") == 0)
			{
				int item;
				cin >> item;
				cout << item << endl;
				q.Push(item);
			}
			else if(strcmp (command, "pop") == 0)
			{
				cout << endl;
				q.Pop();
			}
		} catch (const char *e) {
			cout << "Error " << e << endl;
		}
		q.Show();
		q.Internal();

	}

	return 1;
}

