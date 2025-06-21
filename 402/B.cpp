#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int Q;
	cin >> Q;
	queue <int> a;
	while (Q--)
	{
		int q;
		cin >> q;
		if (q == 1)
		{
			int x;
			cin >> x;
			a.push(x);
		}
		else
		{
			cout << a.front() << endl;
			a.pop();
		}
	}
	return 0;
}