#include <iostream>
#include <vector>

using namespace std;

int k[300005];

int main()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > kind(n + 1);
	for (int i = 1; i <= m; ++i)
	{
		cin >> k[i];
		for (int j = 0; j < k[i]; ++j)
		{
			int a;
			cin >> a;
			kind[a].push_back(i);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int b;
		cin >> b;
		
		for (auto& it : kind[b])
		{
			if (--k[it] == 0) ++ans;
		}
		cout << ans << endl;
	}
	return 0;
}