#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	string x, t;
	cin >> x;

	int point = 0;
	for (int i = 0; i < n; ++i)
	{
		if (x[i] == 'o')
		{
			++point;
			if (!i) x[i + 1] = '.';
			else if (i == n - 1) x[i - 1] = '.';
			else x[i - 1] = '.', x[i + 1] = '.';
		}
	}
	if (point == k)
	{
		for (int i = 0; i < n; ++i)
		{
			if (x[i] == '?') x[i] = '.';
		}
		cout << x;
		return 0;
	}
	t = x;
	bool tmp = 0;
	int l = 0;
	for (int i = 0; i < n; ++i)
	{
		if (tmp && t[i] != '?')
		{
			if (l % 2)
			{
				for (int j = i - l; j < i; j += 2)
				{
					t[j] = 'o';
					if (j != i - 1) t[j + 1] = '.';
				}
				point += l / 2 + 1;
			}
			else point += l / 2;
			tmp = 0, l = 0;
		}

		else if (!tmp && t[i] == '?')
		{
			tmp = 1;
			l = 1;
		}

		else if (tmp && t[i] == '?') ++l;
	}
	if (tmp)
	{
		if (l % 2)
		{
			for (int j = n - l; j < n; j += 2)
			{
				t[j] = 'o';
				if (j != n - 1) t[j + 1] = '.';
			}
			point += l / 2 + 1;
		}
		else point += l / 2;
		tmp = 0, l = 0;
	}

	cout << (k == point ? t : x);
	return 0;
}