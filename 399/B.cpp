#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
	int num, cnt;
};

int main()
{
	int n;
	cin >> n;
	int grade[n];
	vector <node> p;
	for (int i = 0; i < n; ++i)
	{
		node tmp;
		cin >> tmp.num;
		tmp.cnt = i;
		p.push_back(tmp);
	}

	sort(p.begin(), p.end(), [](node& a, node& b) {return a.num > b.num; });

	int k, last = -1;
	for (int i = 0; i < n; ++i)
	{
		if (last != p[i].num)
		{
			k = i + 1;
			last = p[i].num;
		}
		grade[p[i].cnt] = k;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << grade[i] << endl;
	}
	return 0;
}