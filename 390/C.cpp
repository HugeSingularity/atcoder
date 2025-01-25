#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int inf = 1e9;

vector <pair<int, int> >white;

int main()
{
	int h, w;
	cin >> h >> w;
	int l = inf, r = 0, u = inf, d = 0;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			char s;
			cin >> s;
			if (s == '#') 
			{
				l = min(l, j);
				r = max(r, j);
				u = min(u, i);
				d = max(d, i);
			}
			else if (s == '.')
			{
				white.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < (int)white.size(); ++i)
	{
		if (white[i].second >= l && white[i].second <= r && white[i].first >= u && white[i].first <= d)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}