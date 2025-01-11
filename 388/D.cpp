#include <cstdio>

int a[500005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		a[i] -= n - i - 1;
		a[i] += i;
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] >= 0) printf("%d ", a[i]);
		else
		{
			printf("%d ", 0);
			for (int j = n - 1; j > n + a[i]; --j)
			{
				--a[j];
			}
		}
	}
	return 0;
}