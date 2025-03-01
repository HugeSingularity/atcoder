#include <cstdio>

int bird[1000005], group[1000005], nest[1000005];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
	{
		bird[i] = i;
		group[i] = i;
		nest[i] = i;
	}
	while (q--)
	{
		int kind;
		scanf("%d", &kind);
		if (kind == 1)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			bird[a] = nest[b];
		}
		else if (kind == 2)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			group[nest[a]] = b;
			group[nest[b]] = a;
			int tmp = nest[a];
			nest[a] = nest[b];
			nest[b] = tmp;
		}
		else if (kind == 3)
		{
			int a;
			scanf("%d", &a);
			printf("%d\n", group[bird[a]]);
		}
	}
	return 0;
}