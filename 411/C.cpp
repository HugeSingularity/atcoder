#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, q;
	cin >> n >> q;
	vector <bool> a(n, 0);
	int ans = 0;
	for (int i = 0; i < q; ++i)
	{
		int tmp;
		cin >> tmp;
		if (!a[--tmp]) a[tmp] = 1;
		else a[tmp] = 0;
		if (!tmp)
		{
			if (a[tmp] != a[tmp + 1] && a[tmp]) ++ans;
			else if (a[tmp] == a[tmp + 1] && !a[tmp]) --ans;
		}
		else if (tmp == n - 1)
		{
			if (a[tmp - 1] != a[tmp] && a[tmp]) ++ans;
			else if (a[tmp - 1] == a[tmp] && !a[tmp]) --ans;
		}
		else
		{
			if (a[tmp - 1] != a[tmp] && a[tmp] != a[tmp + 1]) ++ans;
			else if (a[tmp - 1] == a[tmp] && a[tmp] == a[tmp + 1]) --ans;
		}
		cout << ans << endl;
	}
	return 0;
}