#include <iostream>

using namespace std;

long long a[300005];

int main()
{
	int n;
	long long sum = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < n; ++i)
	{
		ans += a[i] * (sum - a[i]);
	}

	cout << ans / 2;
	return 0;
}