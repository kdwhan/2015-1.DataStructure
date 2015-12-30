// Lab 010
// Name : Kim Dae Whan
// Student ID : 20123338


void NaturalMerge(int *inputArray, int n, int *outputArray)
{

	int m = 0;

	// first find the start position of the second list
	// set the position to m

	for (int i = 0; i < n; i++)
	{
		if (inputArray[i] > inputArray[i + 1])
		{
			m = i + 1;
			break;
		}
	}
	cout << "n = " << n << ", m = " << m << endl;

	int new_pos = 0; //index of outputArray
	int j = m;// the start index of second list

	int k;
	// merge the two list
	for (int i = 0; i<m; i++)
	{
		if (new_pos<n && j < n)
		{
			if (inputArray[i] < inputArray[j])
			{
				outputArray[new_pos] = inputArray[i];
				++new_pos;
				if (j == n - 1)
					outputArray[new_pos] = inputArray[j];
			}
			else
			{
				outputArray[new_pos] = inputArray[j];
				++new_pos;
				++j;
				k = i;
				--i;
			}
		}
		if (j >= n && new_pos < n)
		{
			outputArray[new_pos] = inputArray[k];
			++new_pos;
			++k;
		}
	}
}
