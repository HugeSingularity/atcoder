#include <iostream>

using namespace std;

int main()
{
	long long x;
	cin >> x;
	long long n = 1, i = 1;
	while (i++)
	{
		n *= i;
		if (n == x)
		{
			cout << i;
			return 0;
		}
	}
}