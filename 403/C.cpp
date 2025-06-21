#include <iostream>
#include <set>
#include <vector> 

using namespace std;

vector <set <int>> permission(200005);
bool f[200005];

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	while (q--)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 1)
		{
			int x, y;
			cin >> x >> y;
			permission[x].insert(y);
		}
		else if (tmp == 2)
		{
			int x;
			cin >> x;
			f[x] = 1;
		}
		else if (tmp == 3)
		{
			int x, y;
			cin >> x >> y;
			if (f[x]) cout << "Yes\n";
			else
			{
				auto it = permission[x].find(y);
				if (it != permission[x].end())
				{
					cout << "Yes\n";
				}
				else cout << "No\n";
			}
		}
	}
	return 0;
}