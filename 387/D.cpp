#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main()
{
	int h, w;
	cin >> h >> w;
	vector <string> s(h);
	int si, sj, gi, gj;
	for (int i = 0; i < h; i++)
	{
		cin >> s[i];
		for (int j = 0; j < w; j++)
		{
			if (s[i][j] == 'S') si = i, sj = j;
			else if (s[i][j] == 'G') gi = i, gj = j;
		}
	}
	vector< vector< pair<int, int> > > walk(2);
	walk[0] = { {0, 1}, {0, -1} };
	walk[1] = { {1, 0}, {-1, 0} };
	int ans = inf;
	for (int k = 0; k < 2; k++)
	{
		vector d(h, vector(w, inf));
		d[si][sj] = 0;
		queue<pair<int, int> > a;
		a.push(make_pair(si, sj));
		while (!a.empty())
		{
			auto [i, j] = a.front();
			a.pop();
			for (auto [x, y] : walk[(i + j + k) & 1])
			{
				int ni = i + x, nj = j + y;
				if (ni >= h || ni < 0 || nj >= w || nj < 0) continue;
				if (s[ni][nj] == '#') continue;
				if (d[ni][nj] != inf) continue;
				d[ni][nj] = d[i][j] + 1;
				a.push(make_pair(ni, nj));
				if (ni == gi && nj == gj)
				{
					break;
				}
			}
		}
		ans = min(ans, d[gi][gj]);
	}
	if (ans == inf) cout << -1;
	else cout << ans;
	return 0;
}