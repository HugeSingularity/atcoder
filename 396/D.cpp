#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool x[11];
int n, m;

struct ed
{
	int v;
	long long w;
};

vector <vector <ed> > edge(11);

long long ans = LLONG_MAX;

void dfs(int u, long long w)
{
	if (u == n)
	{
		ans = min(ans, w);
		return;
	}
	x[u] = 1;
	for (auto& a : edge[u])
	{
		if (!x[a.v])
		{
			dfs(a.v, w ^ a.w);
		}
	}
	x[u] = 0;
	return;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; ++i)
	{
		int u;
		ed tmp1, tmp2;
		cin >> u >> tmp1.v >> tmp1.w;
		edge[u].push_back(tmp1);
		tmp2.v = u;
		tmp2.w = tmp1.w;
		edge[tmp1.v].push_back(tmp2);
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}