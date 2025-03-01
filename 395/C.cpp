#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int inf = 1e9;
map <int, vector <int> > a;

int main()
{
	int n, ans = inf;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		a[tmp].push_back(i);
	}
	for (auto& to : a)
	{
		for (int i = 1; i < (int)to.second.size(); ++i)
		{
			ans = min(ans, to.second[i] - to.second[i - 1] + 1);
		}
	}
	printf("%d", (ans != inf ? ans : -1));
	return 0;
}