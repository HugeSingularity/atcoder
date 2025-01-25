#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long a[n];
	cin >> a[0] >> a[1];
	for (int i = 2; i < n; ++i)
	{
		cin >> a[i];
		if (a[i - 2] * a[i] != a[i - 1] * a[i - 1])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}