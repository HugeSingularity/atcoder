#include <iostream>

using namespace std;

const long long inf = 1e9;
long long n, m, x = 1;

bool pow(int cnt)
{
	long long tmp = 1;
	for (int i = 0; i < cnt; ++i)
	{
		tmp *= n;
		if (tmp > inf) return 0;
	}
	x += tmp;
	if (x > inf) return 0;
	return 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		if (!pow(i))
		{
			cout << "inf";
			return 0;
		}
	}
	cout << x;
	return 0;
}