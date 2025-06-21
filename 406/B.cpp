#include <iostream>

using namespace std;

long long pow(long long a, long long b)
{
	long long res = 1;
	for (int i = 0; i < b; ++i)
	{
		res *= a;
	}
	return res;
}

int l(int a)
{
	int res = 0;
	while (a > 0)
	{
		a /= 10;
		++res;
	}
	return res - 1;
}

int main()
{
	int n, k;
	cin >> n >> k;
	long long ans = 1;
	for (int i = 0; i < n; ++i)
	{
		long long a;
		cin >> a;
		int al = l(a);
		int ansl = l(ans);
		if (al + ansl < k)
		{
			int nowK = k - al - ansl;
			double tmp = (double)ans / (double)pow(10, ansl) * ((double)a / (double)pow(10, al));
			if (tmp < (double)pow(10, nowK)) ans *= a;
			else ans = 1;
		}
		else ans = 1;
	}
	cout << ans;
	return 0;
}