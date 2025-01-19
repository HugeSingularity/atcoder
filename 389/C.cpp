#include <iostream>

using namespace std;

long long head[(int)3e5];

int main()
{
	int L = 0, cnt = 1, q;
	long long now = 0;
	cin >> q;
	while (q--)
	{
		int kind;
		cin >> kind;
		if (kind == 1)
		{
			int l;
			cin >> l;
			head[cnt++] = head[cnt - 1] + l;
		}
		else if (kind == 2)
		{
			now = head[++L];
		}
		else
		{
			int k;
			cin >> k;
			cout << head[k - 1 + L] - now << endl;
		}
	}
	return 0;
}