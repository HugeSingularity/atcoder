#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> mochi;
	int last = 1, a;
	cin >> a;
	mochi.push_back(a);
	for (int i = 1; i < n; ++i)
	{
		cin >> a;
		mochi.push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < mochi.size(); ++i)
	{
		if (mochi[i] * 2 > mochi.back()) break;
		for (int j = last; j < mochi.size(); ++j)
		{
			if (mochi[i] * 2 <= mochi[j])
			{
				ans += mochi.size() - j;
				last = j;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}