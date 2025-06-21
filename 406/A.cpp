#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool x = 0;
	if (a > c) x = 1;
	else if (a == c && b > d) x = 1;
	cout << (x ? "Yes" : "No");
	return 0;
}