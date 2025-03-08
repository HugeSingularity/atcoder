#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int last = 0, cnt = 1;
	bool ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (a == last)
		{
			if (++cnt == 3)
			{
				ans = 1;
				break;
			}
		}
		else cnt = 1;
		last = a;
	}
	cout << (ans ? "Yes" : "No");
	return 0;
}