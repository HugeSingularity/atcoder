#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int last;
	scanf("%d", &last);
	for (int i = 1; i < n; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		if (last >= tmp)
		{
			printf("No");
			return 0;
		}
		last = tmp;
	}
	printf("Yes");
	return 0;
}