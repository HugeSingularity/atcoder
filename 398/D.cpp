#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	queue <pair <int, int> > a, b;
	bool x = 0, y = 0;

	while (n--)
	{
		char s;
		cin >> s;
		if (!x)
		{
			a.push(make_pair(0, 0));
			if (r == 0 && c == 0 && y == 0)
			{
				cout << 1;
				y = 1;
			}

			while (!a.empty())
			{
				pair <int, int> tmp = a.front();
				a.pop();
				if (s == 'N')
				{
					tmp.first -= 1;

				}
				else if (s == 'W')
				{
					tmp.second -= 1;
				}
				else if (s == 'S')
				{
					tmp.first += 1;
				}
				else
				{
					tmp.second += 1;
				}

				if (tmp.first == r && tmp.second == c && y == 0)
				{
					cout << 1;
					y = 1;
				}

				b.push(tmp);
			}

			if (y == 0) cout << 0;
			x = 1, y = 0;
		}
		else
		{
			b.push(make_pair(0, 0));
			if (r == 0 && c == 0 && y == 0)
			{
				cout << 1;
				y = 1;
			}

			while (!b.empty())
			{
				pair <int, int> tmp = b.front();
				b.pop();
				if (s == 'N')
				{
					tmp.first -= 1;

				}
				else if (s == 'W')
				{
					tmp.second -= 1;
				}
				else if (s == 'S')
				{
					tmp.first += 1;
				}
				else
				{
					tmp.second += 1;
				}

				if (tmp.first == r && tmp.second == c && y == 0)
				{
					cout << 1;
					y = 1;
				}

				a.push(tmp);
			}

			if (y == 0) cout << 0;
			x = 0, y = 0;
		}
	}
	return 0;
}