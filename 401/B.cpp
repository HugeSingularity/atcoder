#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	bool x = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		if (s == "login") x = 1;
		else if (s == "logout") x = 0;
		else if (s == "private" && !x) ++ans;
	}
	cout << ans;
	return 0;
}