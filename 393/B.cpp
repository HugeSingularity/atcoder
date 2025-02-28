#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < (int)s.size(); ++i)
	{
		if (s[i] == 'A')
		{
			for (int j = i + 1; j - i < (int)s.size() - j; ++j)
			{
				if (s[j] == 'B' && s[2 * j - i] == 'C') ++ans;
			}
		}
	}
	cout << ans;
}