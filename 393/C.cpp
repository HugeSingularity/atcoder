#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	map <int, int> chart[n + 1];
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		if (u == v) ++ans;
		else
		{
			if (u > v) swap(u, v);
			if (chart[u].count(v)) ++ans;
			else chart[u][v] = 1;
		}
	}
	cout << ans;
	return 0;
}