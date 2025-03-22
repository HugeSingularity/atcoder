#include <iostream>

using namespace std;

int main()
{
	char s;
	bool x = 1;
	int ans = 0;
	while (cin >> s)
	{
		if (x == 1)
		{
			if (s == 'i')
			{
				x = 0;
				continue;
			}
			else ++ans;
		}
		else
		{
			if (s == 'o')
			{
				x = 1;
				continue;
			}
			else ++ans;
		}
	}
	cout << ans + (x ? 0 : 1);
	return 0;
}