#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	vector <long long> black, white;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		long long b;
		cin >> b;
		black.push_back(b);
	}
	for (int i = 0; i < m; ++i)
	{
		long long w;
		cin >> w;
		white.push_back(w);
	}
	sort(black.begin(), black.end());
	sort(white.begin(), white.end());
	int j = white.size() - 1;
	long long ans = 0;
	for (int i = black.size() - 1; i >= 0; --i)
	{
		if (j < 0)
		{
			white[0] = 0;
			j = 0;
		}
		if (black[i] + white[j] <= 0 && black[i] <= 0)
		{
			break;
		}
		if (black[i] + white[j] > 0 && white[j] > 0)
		{
			ans += black[i] + white[j--];
		}
		else ans += black[i];
	}
	cout << ans;
	return 0;
}