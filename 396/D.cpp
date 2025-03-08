#include <iostream>
#include <vector>

using namespace std;

const long long inf = 18e18;
bool x[11];
int n, m;

struct ed
{
	int v;
	long long w;
};

struct r
{
	long long ans;
	bool y;
};

vector <vector <ed> > edge(11);

r dfs(int u, long long ans)
{
	if (u == n)
	{
		r tmp;
		tmp.ans = ans;
		tmp.y = 1;
		return tmp;
	}
	r newAns;
	newAns.ans = inf;
	newAns.y = 0;
	for (auto& a : edge[u])
	{
		if (!x[a.v])
		{
			x[a.v] = 1;
			r tmp = dfs(a.v, ans ^ a.w);
			if (tmp.y)
			{
				newAns.y = 1;
				newAns.ans = min(newAns.ans, tmp.ans);
			}
			x[a.v] = 0;
		}
	}
	return newAns;
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
	long long ans = inf;
	for (auto& a : edge[1])
	{
		x[1] = 1;
		r tmp = dfs(a.v, 0);
		if (tmp.y == 1)
		{
			ans = min(ans, tmp.ans);
		}
	}
	cout << ans;
	return 0;
}