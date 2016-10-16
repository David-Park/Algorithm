#include <iostream>
#define DIV 10007
using namespace std;

int dp[10][1001];

int main()
{
	int n = 0;
	int ans = 0;
	cin >> n;

	for (int i = 0; i < 10; i++)
		dp[i][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[0][i] = dp[0][i - 1];
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[j][i] += dp[k][i - 1];
			}
			dp[j][i] %= DIV;
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		ans += dp[i][n];
		ans %= DIV;
	}

	cout << ans << endl;
	return 0;
}