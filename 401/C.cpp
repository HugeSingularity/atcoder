#include <iostream>

using namespace std;

long long a[1000005];
const long long mod = 1e9;

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		a[i] = 1;
	}
	a[k] = k;
	for (int i = k + 1; i <= n; ++i)
	{
		a[i] = a[i - 1] * 2 - a[i - k - 1] + mod;
		a[i] %= mod;
	}
	cout << a[n];
	return 0;
}