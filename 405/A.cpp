#include <iostream>

using namespace std;

int main()
{
	int r, x;
	cin >> r >> x;
	if (x == 1)
	{
		if (r >= 1600 && r <= 2999)	cout << "Yes";
		else cout << "No";
	}
	else
	{
		if (r >= 1200 && r <= 2399)	cout << "Yes";
		else cout << "No";
	}
	return 0;
}