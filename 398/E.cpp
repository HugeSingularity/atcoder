#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

vector <int> tree[105];
vector <int> blue;
vector <int> red;
queue <pair <int, bool> > a;
map <pair <int, int>, int> c;

bool hasColor[105];

void bfs()
{
	while (!a.empty())
	{
		pair <int, bool> x;
		x = a.front();
		a.pop();
		for (auto& to : tree[x.first])
		{
			if (!hasColor[to])
			{
				hasColor[to] = 1;
				a.push(make_pair(to, (x.second ? 0 : 1)));
				if (x.second) red.push_back(to);
				else blue.push_back(to);
			}
		}
	}
	return;
}

bool find(int u, int v)
{
	bool res = 0;
	for (auto& to : tree[u])
	{
		if (to == v) res = 1;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	blue.push_back(1);
	hasColor[1] = 1;
	a.push(make_pair(1, 1));
	bfs();

	for (auto& tmp1 : blue)
	{
		for (auto& tmp2 : red)
		{
			if (!find(tmp1, tmp2))
			{
				if (tmp1 > tmp2) swap(tmp1, tmp2);
				c[make_pair(tmp1, tmp2)] = 1;
			}
		}
	}

	if (((int)blue.size() * (int)red.size() - n + 1) % 2 == 0)
	{
		int i, j;
		cin >> i >> j;
		c.erase({i, j});
	}
	else cout << "First" << endl;
	while (true)
	{
		auto it = c.begin();
		cout << it->first.first << " " << it->first.second << endl;
		c.erase(it->first);
		int i, j;
		cin >> i >> j;
		if (i == -1) return 0;
		c.erase({ i, j });
	}
}