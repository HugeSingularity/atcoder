#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int tmp1 = (n + 1) / 2;
	int tmp2 = tmp1;
	if (n % 2 == 0) ++tmp2;
	for (int i = 1; i <= n; ++i)
	{
		cout << (i == tmp1 || i == tmp2 ? '=' : '-');
	}
	return 0;
}