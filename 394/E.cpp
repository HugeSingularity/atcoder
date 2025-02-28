#include <iostream>
#include <queue>

using namespace std;

char c[105][105];
int g[105][105];
queue <pair<int, int> > a;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)  //输入及准备工作
		for (int j = 0; j < n; ++j)
		{
			cin >> c[i][j];
			if (i == j)
			{
				g[i][j] = 0;
				a.push(make_pair(i, j));
			}
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i == j) continue;
			if (c[i][j] == '-')
			{
				g[i][j] = -1;
			}
			else
			{
				g[i][j] = 1;
				a.push(make_pair(i, j));
			}
		}

	while (!a.empty())	//求答案
	{
		pair<int, int> b = a.front();
		a.pop();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (c[i][b.first] != '-' && c[i][b.first] == c[b.second][j] && g[i][j] == -1)
				{
					g[i][j] = g[b.first][b.second] + 2;
					a.push(make_pair(i, j));
				}
			}
	}

	for (int i = 0; i < n; ++i)	//输出答案
		for (int j = 0; j < n; ++j)
		{
			cout << g[i][j] << (j == n - 1 ? "\n" : " ");
		}
	return 0;
}