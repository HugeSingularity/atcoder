#include <iostream>

using namespace std;

bool x;
int a[14];

int main()
{
	int b;
	for (int i = 0; i < 7; ++i)
	{
		int tmp;
		cin >> tmp;
		if (++a[tmp] == 3)
		{
			x = 1;
			b = tmp;
		}
	}
	if (x == 1)
	{
		for (int i = 1; i <= 13; ++i)
		{
			if (a[i] >= 2 && i != b)
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}