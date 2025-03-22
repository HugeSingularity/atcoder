#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <int, int> b;

vector <int> a;

int main()
{
	int n; 
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		cin >> tmp;
		if (b.find(tmp) != b.end())
		{
			b[tmp] = -1;
		}
		else
		{
			b[tmp] = i;
			a.push_back(tmp);
		}
	}
	pair <int, int> ans;
	ans.first = 0;
	ans.second = -1;
	for (auto& tmp : a)
	{
		if (b[tmp] != -1)
		{
			if (ans.first < tmp)
			{
				ans.first = tmp;
				ans.second = b[tmp];
			}
		}
	}
	cout << ans.second;
	return 0;
}