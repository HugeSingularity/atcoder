#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	char c[n][n], t[m][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> t[i][j];
		}
	}
	for (int a = 0; a <= n - m; ++a)
	{
		bool x = 1;
		for (int b = 0; b <= n - m; ++b)
		{
			x = 1;
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (c[a + i][b + j] != t[i][j])
					{
						x = 0;
						break;
					}
				}
				if (x == 0) break;
			}
			if (x == 1)
			{
				cout << a + 1 << " " << b + 1;
				break;
			}
		}
		if (x == 1) break;
	}
	return 0;
}