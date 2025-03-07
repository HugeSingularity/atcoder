#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector <int> a;

	int maxA = 0;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
		maxA = max(a[i], maxA);
	}
	
	vector <int> s(maxA + 1), u(maxA + 1);

	for (int i = 0; i < n; ++i)
	{
		++s[a[i]];
	}

	for (int i = 1; i <= maxA; ++i)
	{
		int t = 0;
		for (int j = i; j <= maxA; j += i)
		{
			t += s[j];
		}

		if (t >= k)
		{
			for (int j = i; j <= maxA; j += i)
			{
				u[j] = max(u[j], i);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << u[a[i]] << endl;
	}
	return 0;
}