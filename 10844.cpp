#include <iostream>
using namespace std;

#define DIV 1000000000
long long dp[10][101];

int main()
{
	int n = 0;
	long long ans = 0;
	cin >> n;

	for (int i = 0; i <= 9; i++)
	{
		dp[i][1] = 1;
		dp[i][2] = 2;
	}
	dp[0][2] = 1;
	dp[9][2] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[0][i] = dp[1][i - 1];
		dp[9][i] = dp[8][i - 1];
		for (int j = 1; j <= 8; j++)
		{
			dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % DIV;
		}
	}

	for (int i = 1; i <= 9; i++)
		ans += dp[i][n] % DIV;

	std::cout << ans << endl;
	return 0;
}