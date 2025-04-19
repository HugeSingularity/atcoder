#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		set <pair <int, int> > answers;
		vector <int> A;
		vector <vector <int> > B(n + 1);
		for (int i = 0; i < 2 * n; ++i)
		{
			int tmp;
			cin >> tmp;
			A.push_back(tmp);
		}
		for (int i = 0; i < 2 * n; ++i)
		{
			B[A[i]].push_back(i);
		}
		for (int i = 0; i < 2 * n - 1; ++i)
		{
			int a = A[i], b = A[i + 1];
			if (B[a][0] + 1 == B[a][1]) continue;
			if (B[b][0] + 1 == B[b][1]) continue;
			vector<int> tmp{ B[a][0], B[a][1], B[b][0], B[b][1] };
			sort(tmp.begin(), tmp.end());
			if (tmp[0] + 1 == tmp[1] && tmp[2] + 1 == tmp[3]) answers.emplace(minmax(a, b));;
		}
		cout << answers.size() << endl;
	}
	return 0;
}