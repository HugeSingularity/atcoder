#include <iostream>

using namespace std;

int main()
{
	char a, b, tmp;
	cin >> a;
	for (int i = 0; i < 3; ++i) cin >> tmp;
	cin >> b;
	if (a == 's' && b == 's') cout << 1;
	else if (a == 'f' && b == 'f') cout << 4;
	else if (a == 's') cout << 2;
	else cout << 3;
	return 0;
}