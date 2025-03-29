#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	char s1[n + 1], s2[n + 1];
	for (int i = 0; i < n; ++i)
	{
		cin >> s1[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> s2[i];
		if (s1[i] != s2[i]) ++ans;
	}
	cout << ans;
	return 0;
}