#include <cstdio>

char color[55][55];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int j = n + 1 - i;
		bool c = i % 2;
		if (i <= j)
		{
			for (int k = i; k <= j; ++k)
			{
				for (int a = i; a <= j; ++a)
				{
					if (c) color[k][a] = '#';
					else color[k][a] = '.';
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			printf("%c", color[i][j]);
		}
		printf("\n");
	}
	return 0;
}