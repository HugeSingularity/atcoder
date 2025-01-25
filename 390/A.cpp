#include <iostream>

using namespace std;

int main()
{
	int a[6];
	bool tmp = 0, ans = 0;
	for (int i = 1; i <= 5; i++)
	{
		cin >> a[i];
		if (a[i] != i)
		{
			if (ans == 1)
			{
				ans = 0;
				break;
			}
			if (tmp == 1)
			{
				ans = 1;
			}
			else tmp = 1;
		}
		else if (tmp == 1) tmp = 0;
	}
	if (ans == 1) cout << "Yes";
	else cout << "No";
	return 0;
}