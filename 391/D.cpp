#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;

struct node
{
	int t, num;
	node(int t, int num) :t(t), num(num) {}
};

int dis[int(2e5) + 5], a[int(2e5) + 5];

int main()
{
	int n, w;
	cin >> n >> w;
	vector<node> cols[w + 1];
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		cin >> x >> y;
		cols[x].push_back(node(y, i));
	}
	int sum = 0;
	for (int i = 1; i <= w; ++i)
	{
		sort(cols[i].begin(), cols[i].end(), [](node a, node b) {
			return a.t < b.t;
			});
		for (int j = 0; j < (int)cols[i].size(); ++j)
		{
			a[cols[i][j].num] = j;
			sum = max(j, sum);
		}
	}
	for (int i = 1; i <= w; ++i)
	{
		if (0 >= cols[i].size())
		{
			dis[0] = inf;
			break;
		}
		else dis[0] = max(dis[0], cols[i][0].t);
	}
	for (int i = 1; i <= sum; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			if (i >= cols[j].size())
			{
				dis[i] = inf;
				break;
			}
			else dis[i] = max(dis[i], cols[j][i].t);
		}
		dis[i] = max(dis[i - 1] + 1, dis[i]);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int time, p;
		cin >> time >> p;
		if (dis[a[p]] > time) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}