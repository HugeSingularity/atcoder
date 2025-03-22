#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector <int> edge[200005];
int n, k, c[200005], s[200005];
bool x;

int dfs(int last, int now)
{
	for (auto& ed : edge[now])
	{
		if (ed == last) continue;
		s[now] += dfs(now, ed);
	}
	s[now] += 1;
	if (s[now] < k && c[now] < 2)
	{
		return s[now];
	}
	if (s[now] == k && c[now] <= 2)
	{
		--c[last];
		return 0;
	}
	cout << "No";
	exit(EXIT_SUCCESS);
}

int main()
{
	cin >> n >> k; 
	int tmp = n * k;
	for (int i = 1; i < tmp; ++i)
	{
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		++c[u], ++c[v];
	}
	for (int i = 2; i <= tmp; ++i)
	{
		--c[i];
	}
	dfs(0, 1);
	cout << "Yes";
	return 0;
}