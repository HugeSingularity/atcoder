#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n], b[m + 1];
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		a[i] = x;
		++b[x];
	}

	for (int i = 1; i <= m; ++i)
	{
		if (!b[i])
		{
			cout << 0;
			return 0;
		}
	}

	for (int i = n - 1; i >= 0; --i)
	{
		if (--b[a[i]] == 0)
		{
			cout << n - i;
			return 0;
		}
	}
}