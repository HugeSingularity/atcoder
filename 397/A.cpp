#include <iostream>

using namespace std;

int main()
{
	double x;
	cin >> x;
	if (x >= 38) cout << 1;
	else if (x >= 37.5) cout << 2;
	else cout << 3;
	return 0;
}