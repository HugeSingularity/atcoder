#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long inf = 9e18;
vector <int> edge[2][200005];
long long n, m, x, dp[200005][2];
bool b[200005];

void dfs(int u)
{
	if (dp[u][0] != inf || b[u]) return;
	b[u] = 1;
	for (auto& v : edge[0][u])
	{
		dfs(v);
	}
	for (auto& v : edge[1][u])
	{
		dfs(v);
	}
	for (auto& v : edge[0][u])
	{
		dp[u][0] = min(dp[u][0], dp[v][1] + 1 + x);
		dp[u][1] = min(dp[u][1], dp[v][1] + 1);
	}
	for (auto& v : edge[1][u])
	{
		dp[u][0] = min(dp[u][0], dp[v][0] + 1);
		dp[u][1] = min(dp[u][1], dp[v][0] + 1 + x);
	}
	return;
}

int main()
{
	cin >> n >> m >> x;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		edge[0][u].push_back(v);
		edge[1][v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
	{
		dp[i][0] = inf;
		dp[i][1] = inf;
	}
	dp[1][0] = 0, dp[1][1] = x;

	dfs(n);
	printf("%lld", min(dp[n][0], dp[n][1]));
	return 0;
}