#include <iostream>

using namespace std;

int father[200005], l[200005];

int find(int a)
{
	return a == father[a] ? a : father[a] = find(father[a]);
}

bool Union(int a, int b)
{
	int rootA = find(a), rootB = find(b);
	if (rootA == rootB) return 1;
	if (l[rootA] < l[rootB])
	{
		father[rootA] = rootB;
	}
	else if (l[rootA] > l[rootB])
	{
		father[rootB] = rootA;
	}
	else
	{
		father[rootB] = rootA;
		++l[rootA];
	}
	return 0;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		father[i] = i;
		l[i] = 1;
	}

	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		if (Union(u, v)) ++ans;
	}
	cout << ans;
	return 0;
}