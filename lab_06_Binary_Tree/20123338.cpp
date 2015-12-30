// Lab 006 
// Name : Kim Dae Whan
// Student ID : 20123338

template <class T>
void  ArrayTree<T>::PreOrder(const int node)
{
	if (node > treeSize)
		return;
	else
	{
		if (tree[node] != 0)
		{
			cout << tree[node] << " ";
			PreOrder(node * 2);//leftchild
			PreOrder(node * 2 + 1);//rightchild
		}
		else
			return;
	}
}

template <class T>
void  ArrayTree<T>::InOrder(const int node)
{
	if (node > treeSize)
		return;
	else
	{
		if (tree[node] != 0)
		{
			InOrder(node * 2);//leftChild
			cout << tree[node] << " ";
			InOrder(node * 2 + 1);//rightChild
		}
		else
			return;
	}
}

template <class T>
void  ArrayTree<T>::PostOrder(const int node)
{
	if (node > treeSize)
		return;
	else
	{
		if (tree[node] != 0)
		{
			PostOrder(node * 2);//leftChild
			PostOrder(node * 2 + 1);//rightChild
			cout << tree[node] << " ";
		}
		else
			return;
	}

}
