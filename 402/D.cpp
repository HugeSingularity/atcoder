#include <iostream>

using namespace std;

int distance(int a, int b, int c)
{
	int ans1 = abs(a - b);
	int ans2 = c - ans1;
	return min(ans1, ans2);
}

int main()
{
	int n, m;
}