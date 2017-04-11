#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[300001];

const bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}

int main()
{
	int n = 0, s = 0;
	scanf("%d %d", &n, &s);
	vector<pair<int, int>> p(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &p[i].first, &p[i].second);

	sort(p.begin() + 1, p.end(), comp);

	dp[1] = p[1].second;
	for (int i = 2; i <= n; i++)
	{
		int tmp = 0;
		for (int k = i - 1; k >= 1; k--)
		{
			if (p[i].first - p[k].first < s) continue;

			tmp = max(tmp, dp[k]);
		}

		dp[i] = tmp + p[i].second;
	}

	printf("%d\n", dp[n]);
	return 0;
}