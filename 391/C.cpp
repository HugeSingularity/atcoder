#include <iostream>

using namespace std;

int nest[(int)1e6 + 5], bird[(int)1e6 + 5];

int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		bird[i] = i;
		nest[i] = 1;
	}
	int ans = 0;
	while (q--)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 1)
		{
			int p, h;
			cin >> p >> h;
			--nest[bird[p]], ++nest[h];
			if (nest[bird[p]] == 1) --ans;
			if (nest[h] == 2) ++ans;
			bird[p] = h;
		}
		else cout << ans << endl;
	}
	return 0;
}