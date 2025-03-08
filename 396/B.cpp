#include <iostream>
#include <stack>

using namespace std;

stack <int> a;

int main()
{
	int q;
	cin >> q;
	for (int i = 0; i < 100; ++i)
	{
		a.push(0);
	}
	while (q--)
	{
		int kind;
		cin >> kind;
		if (kind == 1)
		{
			int tmp;
			cin >> tmp;
			a.push(tmp);
		}
		else
		{
			cout << a.top() << endl;
			a.pop();
		}
	}
	return 0;
}