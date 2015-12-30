#include <iostream>
using namespace std;

int Combi(int n, int m);

int main() {
	int n, m;
	while (1) {
		cerr << "Enter n m : " << endl;
		cin >> n >> m;
		if (n == 0) return 1;
		cout << "Combination(" << n << ", " << m << ") : " <<
			Combi(n, m) << endl;
	}

	return 1;
}

int Combi(int n, int m)
{
	if (m == n || m == 0)
		return 1;
	else
		return Combi(n - 1, m) + Combi(n - 1, m - 1);
}