#include <iostream>

using namespace std;

int main()
{
	string p;
	int l;
	cin >> p >> l;
	if (p.length() < l) cout << "No";
	else cout << "Yes";
	return 0;
}