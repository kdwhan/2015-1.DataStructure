// HW 1
// Name :
// Student ID :



template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
	// NEED TO IMPLEMENT 

}

// If number of elements in the stack is 0, return true else return false
template <class T>
inline bool Stack<T>::IsEmpty() const
{

	// NEED TO IMPLEMENT
}

template <class T>
inline T & Stack<T>::Top() const
{
	// NEED TO IMPLEMENT
}

template <class T>
void Stack<T>::Push(const T & item)
{
	// NEED TO IMPLEMENT
}

template <class T>
void Stack<T>::Pop()
{
	// NEED TO IMPLEMENT
}


void Path(const int m, const int p)
{// Output a path (if any) in the maze; 

	// start at (1,1)
	mark[1][1] = 1;

	// NEED TO IMPLEMENT

	cout << "No path in the maze." << endl;
}


