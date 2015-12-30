// HW 2 : Binary Search Tree
// Name : Kim Dae Whan
// Student ID : 20123338


template <class T>
bool  BinaryST<T>::Insert(T item)
{
	BSTNode<T> *current = root;
	BSTNode<T> *InNode = new BSTNode<T>(item);

	if (root == NULL)
	{
		root = new BSTNode<T>(item);
		return true;
	}
	while (current)
	{
		if (current->data.key == item.key)
		{
			current->data.val = item.val;
			return false;
		}
		else if (current->data.key > item.key)
		{
			if (current->lC) // left 있으면 이동
				current = current->lC;
			else
			{//left 없으면 만들기
				current->lC = InNode;
				return true;
			}
		}
		else
		{
			if (current->rC)//right 있으면 이동
			{
				current = current->rC;
			}
			else
			{//right 없으면 만들기
				current->rC = InNode;
				return true;
			}
		}
	}
	return true;
}

template <class T>
T BinaryST<T>::Get(T item)
{
	BSTNode<T> *current = root;

	while (current)
	{
		if (current->data.key == item.key)
			return current->data;
		else if (current->data.key > item.key)
			current = current->lC;
		else
			current = current->rC;
	}
	return T(-1);
}


template <class T>
bool  BinaryST<T>::Delete(T item)
{
	bool check = false; // key값 확인용 
	BSTNode<T> *before = root;
	BSTNode<T> *del = NULL;

	if (before == NULL)
		return false;

	//root 삭제
	if (before->data.key == item.key)
	{
		del = root;

		//양쪽 다 없을때 1
		if ((del->lC == NULL) && (del->rC == NULL))
			root = NULL;

		//한쪽만 있을때 2
		else if ((del->lC != NULL && del->rC == NULL) || (del->lC == NULL && del->rC != NULL))
		{
			if (del->lC == NULL) // 오른쪽 있음
				root = del->rC;
			else                 //왼쪽 있음
				root = del->lC;
		}

		//둘다 있을때 3
		else
		{
			BSTNode<T> *temp_before = del->rC;
			BSTNode<T> *change = NULL;

			//height == 2
			if (temp_before->lC == NULL)
			{
				change = temp_before;
				change->lC = root->lC;
				root = change;
			}

			//height>2
			else
			{
				while (temp_before->lC->lC != NULL)
					temp_before = temp_before->lC;

				change = temp_before->lC;

				if (change->rC)
				{
					change->lC = root->lC;
					temp_before->lC = change->rC;
					change->rC = del->rC;
					root = change;
				}
				else
				{
					change->lC = root->lC;
					temp_before->lC = change->rC;
					change->rC = del->rC;
					root = change;
				}
			}
		}
		delete del;
		return true;
	}

	//이전 노드 찾기
	while (before)
	{
		if (((before->lC != NULL) && (before->lC->data.key == item.key)) || ((before->rC != NULL) && (before->rC->data.key == item.key)))
		{
			check = true;
			break;
		}
		else if (before->data.key > item.key)
			before = before->lC;
		else
			before = before->rC;
	}

	if (check == false)
		return false;

	//lc 삭제
	if (before->lC->data.key == item.key)
	{
		del = before->lC;

		//1
		if ((del->lC == NULL) && (del->rC == NULL))
			before->lC = NULL;

		//2
		else if (((del->lC != NULL) && (del->rC == NULL)) || ((del->lC == NULL) && (del->rC != NULL)))
		{
			if (del->lC != NULL)
				before->lC = del->lC;
			else
				before->lC = del->rC;
		}

		//3
		else
		{
			BSTNode<T> *temp_before = del->rC;
			BSTNode<T> *change = NULL;

			if (temp_before->lC == NULL)
			{
				change = temp_before;

				change->lC = del->lC;
				before->lC = change;
			}

			else
			{
				while (temp_before->lC->lC != NULL)
					temp_before = temp_before->lC;

				change = temp_before->lC;

				if (change->rC)
				{
					change->lC = del->lC;
					temp_before->lC = change->rC;
					change->rC = del->rC;
					before->lC = change;
				}
				else
				{
					change->lC = del->lC;
					temp_before->lC = NULL;
					change->rC = del->rC;
					before->lC = change;
				}
			}
		}

		delete del;
		return true;
	}

	//rc 삭제
	else
	{
		del = before->rC;
		//1
		if ((del->lC == NULL) && (del->rC == NULL))
			before->rC = NULL;

		//2
		else if (((del->lC != NULL) && (del->rC == NULL)) || ((del->lC == NULL) && (del->rC != NULL)))
		{
			if (del->lC != NULL)
				before->rC = del->lC;
			else
				before->rC = del->rC;
		}

		//3
		else
		{
			BSTNode<T> *temp_before = del->rC;
			BSTNode<T> *change = NULL;

			if (temp_before->lC == NULL)
			{
				change = temp_before;

				change->lC = del->lC;
				before->rC = change;
			}
			else
			{
				while (temp_before->lC->lC != NULL)
					temp_before = temp_before->lC;

				change = temp_before->lC;

				if (change->rC)
				{
					change->lC = del->lC;
					temp_before->lC = change->rC;
					change->rC = del->rC;
					before->rC = change;
				}
				else
				{
					change->lC = del->lC;
					temp_before->lC = change->rC;
					change->rC = del->rC;
					before->rC = change;
				}
			}
		}
		delete del;
		return true;
	}
}

template <class T>
void  BinaryST<T>::PreOrder(BSTNode<T> *ptr)
{
	if (ptr != NULL)
	{
		cout << ptr->data.key << "(" << ptr->data.val << ") ";
		PreOrder(ptr->lC);
		PreOrder(ptr->rC);
	}

}

template <class T>
void  BinaryST<T>::InOrder(BSTNode<T> *ptr)
{
	if (ptr != NULL)
	{
		InOrder(ptr->lC);
		cout << ptr->data.key << "(" << ptr->data.val << ") ";
		InOrder(ptr->rC);
	}

}

template <class T>
void  BinaryST<T>::PostOrder(BSTNode<T> *ptr)
{
	if (ptr != NULL)
	{
		PostOrder(ptr->lC);
		PostOrder(ptr->rC);
		cout << ptr->data.key << "(" << ptr->data.val << ") ";
	}

}

template <class T>
int  BinaryST<T>::Count(BSTNode<T> *ptr)
{
	int cnt = 0;

	if (ptr != NULL)
	{
		cnt += Count(ptr->lC);
		cnt += Count(ptr->rC);
		cnt++;
	}
	return cnt;
}

template <class T>
int  BinaryST<T>::Height(BSTNode<T> *ptr)
{
	int cnt = 0;
	int cnt2 = 0;

	if (ptr == NULL)
		return 0;
	else
	{
		cnt = Height(ptr->rC);
		cnt2 = Height(ptr->lC);

		return cnt > cnt2 ? cnt + 1 : cnt2 + 1;
	}
}


