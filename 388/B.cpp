#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, d;
	cin >> n >> d;
	int t[n], l[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> t[i] >> l[i];
	}
	for (int i = 1; i <= d; ++i)
	{
		int w[n];
		for (int j = 0; j < n; ++j)
		{
			w[j] = t[j] * (l[j] + i);
		}
		sort(w, w + n);
		cout << w[n - 1] << endl;
	}
	return 0;
}