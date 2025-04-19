#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long a = 1, b, c = 2, ans = 0;
	for (b = (long long)sqrt(n / 2); b > 0; --b)
	{
		if (b % 2 == 0) continue;
		ans += a;
		while (b * b * c * 2 <= n)
		{
			++ans;
			++a;
			c *= 2;
		}
	}
	cout << ans;
	return 0;
}