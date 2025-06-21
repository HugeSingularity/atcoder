#include <iostream>
#include <queue>

using namespace std;

char s[1005][1005];

int main()
{
	int h, w;
	cin >> h >> w;
	queue <pair <int, int> > x;

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
		{
			cin >> s[i][j];
			if (s[i][j] == 'E')
				x.push({ i, j });
		}

	while (!x.empty())
	{
		pair <int, int> hw;
		hw = x.front();
		x.pop();
		int x1 = hw.first - 1, x2 = hw.first + 1;
		int y1 = hw.second - 1, y2 = hw.second + 1;
		if (x1 >= 0 && s[x1][hw.second] == '.')
		{
			s[x1][hw.second] = 'v';
			x.push({ x1, hw.second });
		}
		if (x2 < h && s[x2][hw.second] == '.')
		{
			s[x2][hw.second] = '^';
			x.push({ x2, hw.second });
		}
		if (y1 >= 0 && s[hw.first][y1] == '.')
		{
			s[hw.first][y1] = '>';
			x.push({ hw.first, y1 });
		}
		if (y2 < w && s[hw.first][y2] == '.')
		{
			s[hw.first][y2] = '<';
			x.push({ hw.first, y2 });
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << s[i][j];
		}
		cout << '\n';
	}
	return 0;
}