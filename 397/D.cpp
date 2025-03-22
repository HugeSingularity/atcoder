#include <cstdio>

using namespace std;

long long finding(long long a, long long b, long long c)
{
	long long l = 1, r = 6e8 + 1;
	while (r - l > 1)
	{
		long long mid = (l + r) / 2;
		if (a * mid * mid + b * mid + c <= 0)
			l = mid;
		else
			r = mid;
	}
	if (a * l * l + b * l + c == 0)
		return l;
	return -1;
}

int main()
{
	long long n;
	scanf("%lld", &n);
	for (long long d = 1; d * d * d <= n; ++d)
	{
		if (n % d != 0) continue;
		long long k = finding(3, 3 * d, d * d - n / d);
		if (k != -1)
		{
			printf("%lld %lld", k + d, k);
			return 0;
		}
	}
	printf("-1");
	return 0;
}