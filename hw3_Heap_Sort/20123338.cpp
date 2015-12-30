// Homework 3
// Name : Kim Dae Whan
// Student ID : 20123338


template <class T>
void  HeapSort<T>::Adjust(const int root, int n)
{	// adjust binary tree with root "root" to satisfy heap property.
	// The left and right subtrees of "root" already satisfy the heap
	// property. No node index is > n.

	//	cerr << "NEED TO IMPLEMENT" << endl;
	T e = heap[root];
	int j;
	for (j = 2 * root; j <= n; j *= 2)
	{
		if (j < n && heap[j] < heap[j + 1]) j++;
		if (e >= heap[j]) break;

		heap[j / 2] = heap[j];
	}
	heap[j/2] = e;
}

template <class T>
void  HeapSort<T>::Sort()
{	// sort heap[1:n] into nondecreasing order
	//	cerr << "NEED TO IMPLEMENT" << endl;
	for (int i = heapSize / 2; i >= 1; i--)
	{
		Adjust(i, heapSize);
	}
	ShowArray();
	for (int i = heapSize - 1; i >= 1; i--)
	{
		int temp = heap[1];
		heap[1] = heap[i+1];
		heap[i+1] = temp;

		Adjust(1, i);
		ShowArray();
	}

}
