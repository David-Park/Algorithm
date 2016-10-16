#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];
int p[1001];
int main()
{
	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> p[i];

	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int maximum = 0;
		for (int j = 0; j < i; j++)
		{
			maximum = max(maximum, dp[j] + p[i - j]);
		}

		dp[i] = maximum;
	}

	cout << dp[n] << endl;
	return 0;
}