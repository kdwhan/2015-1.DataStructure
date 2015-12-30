// Lab 005 
// Name : kim dae whan
// Student ID : 20123338


template <class T>
inline bool Queue<T>::IsEmpty() const {

	if(front == rear)
		return true;
	else
		return false;

}


template <class T>
void Queue<T>::Push (const T& x)
{
	// Add x at rear of queue

	rear = (rear + 1) % capacity;
	queue[rear] = x;

	// NEED TO IMPLEMENT
	if ((rear + 1) % capacity == front)
		throw "Queue is Full";


}

template <class T>
void Queue<T>::Pop ()
{	// Delete front element from queue

	front = (front+1)%capacity;
	queue[front].~T();


	// NEED TO IMPLEMENT

	if(IsEmpty())
	throw "Queue is empty. Cannot delete";

}

template <class T>
void Queue<T>::Show ()
{
	// Show the elements from the front to read
	cout<<"Queue : ";
	for (int i = front + 1; i < rear + 1; i++)
		cout << queue[i] << " ";
	// NEED TO IMPLEMENT
	cout<<endl;
}



