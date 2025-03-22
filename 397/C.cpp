#include <iostream>
#include <utility>

using namespace std;

pair <int, int> b[300005];
int a[300005];

int main()
{
	int n; 
	cin >> n;
	cin >> a[0];
	++b[a[0]].first;
	int ans = 1;
	for (int i = 1; i < n; ++i)
	{
		cin >> a[i];
		if (!b[a[i]].second++)
		{
			++ans;
		}
	}

	int tmp = ans;
	for (int i = 1; i < n - 1; ++i)
	{
		if (!b[a[i]].first && b[a[i]].second > 1)
		{
			++tmp;
		}
		else if (b[a[i]].first && b[a[i]].second == 1)
		{
			--tmp;
		}
		++b[a[i]].first;
		--b[a[i]].second;
		ans = max(tmp, ans);
	}
	cout << ans;
}