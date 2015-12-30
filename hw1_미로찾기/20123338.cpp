// HW 1
// Name : Kim Dae Whan
// Student ID : 20123338

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
	if (capacity < 1) throw "Stack capacity must be >0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const
{
	return top == -1;
}

template <class T>
inline T & Stack<T>::Top() const
{
	if (IsEmpty()) throw "Stack is Empty";

	return stack[top];
}

template <class T>
void Stack<T>::Push(const T & item)
{
	if (top == capacity - 1)
		capacity *= 2;

	stack[++top] = item;
}

template <class T>
void Stack<T>::Pop()
{
	if (IsEmpty()) throw "Stack is Empty, Cannot delete";
	stack[top--].~T();
}

void Path(const int m, const int p)
{
	mark[1][1] = 1;	// start at (1,1)
	Stack <int> stack(m*p);

	int ans[1000], x = 1, y = 1, cnt = 2;

	stack.Push(x);
	stack.Push(y);

	while (!((x == m) && (y == p)))
	{
		//E
		if (!maze[x][y + 1] && !mark[x][y + 1])
		{
			mark[x][++y] = 1;
			stack.Push(x);
			stack.Push(y);
			cnt += 2;
		}
		//SE
		else if (!maze[x + 1][y + 1] && !mark[x + 1][y + 1])
		{
			mark[++x][++y] = 1;
			stack.Push(x);
			stack.Push(y);
			cnt += 2;
		}
		//NE
		else if (!maze[x - 1][y + 1] && !mark[x - 1][y + 1])
		{
			mark[--x][++y] = 1;
			stack.Push(x);
			stack.Push(y);
			cnt += 2;
		}
		//N
		else if (!maze[x - 1][y] && !mark[x - 1][y])
		{
			mark[--x][y] = 1;
			stack.Push(x);
			stack.Push(y);
			cnt += 2;
		}
		//NW
		else if (!maze[x - 1][y - 1] && !mark[x - 1][y - 1])
		{
			mark[--x][--y] = 1;
			stack.Push(x);
			stack.Push(y);
			cnt += 2;
		}
		//W
		else if (!maze[x][y - 1] && !mark[x][y - 1])
		{
			mark[x][--y] = 1;
			stack.Push(x);
			stack.Push(y);
			cnt += 2;
		}
		//SW
		else if (!maze[x + 1][y - 1] && !mark[x + 1][y - 1])
		{
			mark[++x][--y] = 1;
			stack.Push(x);
			stack.Push(y);
			cnt += 2;
		}
		//S
		else if (!maze[x + 1][y] && !mark[x + 1][y])
		{
			mark[++x][y] = 1;
			stack.Push(x);
			stack.Push(y);
			cnt += 2;
		}
		else
		{
			stack.Pop();
			stack.Pop();
			y = stack.Top();
			stack.Pop();
			x = stack.Top();
			stack.Push(y);
			cnt -= 2;
		}

	}

	while (!stack.IsEmpty())
	{
		for (int i = cnt - 1; i >= 0; i--){
			ans[i] = stack.Top();
			stack.Pop();
		}
		for (int i = 0; i < cnt; i++){
			if (i % 2 == 0)
				cout << "(" << ans[i] << ",";
			else
				cout << ans[i] << ")" << endl;
		}
	}

}
