// Lab 005 
// Name : ±Ë¥Î»Ø 
// Student ID : 20123338


template <class T>
inline bool Queue<T>::IsEmpty() const {

	if (rear == front)
		return true;
	else
		return false;
}


template <class T>
void Queue<T>::Push(const T& x)
{
	// Add x at rear of queue

	// NEED TO IMPLEMENT
	// if queue full, throw the following message
	if ((rear + 1) % capacity == front)
		throw "Queue is Full";
	else
	{
		rear = (rear + 1) % capacity;
		queue[rear] = x;
	}


}

template <class T>
void Queue<T>::Pop()
{	// Delete front element from queue

	// NEED TO IMPLEMENT

	// if queue is empty, throw the following message
	if (IsEmpty())
		throw "Queue is empty. Cannot delete";
	else
	{
		front = (front + 1) % capacity;
		queue[front].~T();
	}
}

template <class T>
void Queue<T>::Show()
{
	// Show the elements from the front to read

	// NEED TO IMPLEMENT
	cout << "Queue :";

	if (front <= rear)
	{
		for (int j = front + 1; j < rear + 1; j++)
		{
			cout << queue[j] << " ";
		}
	}
	else
	{
		for (int j = front + 1; j < capacity; j++)
		{
			cout << queue[j] << " ";
		}
		for (int j = 0; j < rear + 1; j++)
		{
			cout << queue[j] << " ";
		}
	}
	cout << endl;
}



// Lab 005 

// Name : kim dae whan

// Student ID : 20123338





template <class T>

inline bool Queue<T>::IsEmpty() const {



	if (front == rear)

		return true;

	else

		return false;



}





template <class T>

void Queue<T>::Push(const T& x)

{

	// Add x at rear of queue





	// NEED TO IMPLEMENT

	if ((rear + 1) % capacity == front)

		throw "Queue is Full";

	else

	{

		rear = (rear + 1) % capacity;

		queue[rear] = x;

	}

}



template <class T>

void Queue<T>::Pop()

{	// Delete front element from queue









	// NEED TO IMPLEMENT



	if (IsEmpty())

		throw "Queue is empty. Cannot delete";



	else

	{

		front = (front + 1) % capacity;

		queue[front].~T();

	}

}



template <class T>

void Queue<T>::Show()

{

	cout << "Queue : ";

	// Show the elements from the front to read

	if (front <= rear)

	{

		for (int j = front + 1; j < rear + 1; j++)

		{

			cout << queue[j] << " ";

		}

	}

	else

	{

		for (int j = front + 1; j < capacity; j++)

		{

			cout << queue[j] << " ";

		}

		for (int j = 0; j < rear + 1; j++)

		{

			cout << queue[j] << " ";

		}

	}

	cout << endl;

	// NEED TO IMPLEMENT



}







