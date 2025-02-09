#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> f[14];

int main()
{
	int n;
	cin >> n;
	int l = pow(3, n);
	vector<char> a[n + 1];
	for (int i = 0; i < l; ++i)
	{
		char tmp;
		cin >> tmp;
		a[0].push_back(tmp);
		f[0].push_back(1);
	}
	for (int i = 1; i <= n; ++i)
	{
		l /= 3;
		for (int j = 0; j < l; ++j)
		{
			if (a[i - 1][3 * j] == a[i - 1][3 * j + 1] && a[i - 1][3 * j + 1] == a[i - 1][3 * j + 2])
			{
				int tmp = f[i - 1][3 * j] + f[i - 1][3 * j + 1] + f[i - 1][3 * j + 2] - max(max(f[i - 1][3 * j], f[i - 1][3 * j + 1]), f[i - 1][3 * j + 2]);
				f[i].push_back(tmp);
				a[i].push_back(a[i - 1][3 * j]);
			}
			else if (a[i - 1][3 * j] == a[i - 1][3 * j + 1])
			{
				int tmp = min(f[i - 1][3 * j], f[i - 1][3 * j + 1]);
				f[i].push_back(tmp);
				a[i].push_back(a[i - 1][3 * j]);
			}
			else if (a[i - 1][3 * j] == a[i - 1][3 * j + 2])
			{
				int tmp = min(f[i - 1][3 * j], f[i - 1][3 * j + 2]);
				f[i].push_back(tmp);
				a[i].push_back(a[i - 1][3 * j]);
			}
			else if (a[i - 1][3 * j + 1] == a[i - 1][3 * j + 2])
			{
				int tmp = min(f[i - 1][3 * j + 1], f[i - 1][3 * j + 2]);
				f[i].push_back(tmp);
				a[i].push_back(a[i - 1][3 * j + 1]);
			}
		}
	}
	cout << f[n][0];
	return 0;
}