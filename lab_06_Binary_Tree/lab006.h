// Lab 006 
// Name :
// Student ID :

#include<iostream>
#include<string.h>
using namespace std;

// ---------- Heap class -------------
template <class T>
class ArrayTree
{
public :
	ArrayTree(int theCapacity = 256);	// constructor

	void Init(const T *, int);
	void InOrder(const int node);
	void PreOrder(const int node);
	void PostOrder(const int node);
	void Show();
private :
	T* tree; // tree
	int treeSize;	// number of elements in tree
	int capacity;	// size of the tree tree
};

template<class T>
ArrayTree<T>::ArrayTree(int theCapacity)
{ // ArrayTree constructor. 
	capacity = theCapacity;
	tree = new T[capacity];	// tree[0] is not used
	treeSize = 0;
}


template <class T>
void ArrayTree<T>::Show()
{ // Show all the element in sequence
	cout << "Tree : - ";

	// print all the nodes in the tree
	for(int i = 1; i <= treeSize; i++)
		cout << tree[i] << "  ";
	cout << endl;
}

template <class T>
void  ArrayTree<T>::Init(const T *es, int n)
{	// initialize the tree by using the input
	treeSize = n;
	for(int i = 1; i <= n; i++)
		tree[i] = es[i];
}

