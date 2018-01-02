#include <iostream>
using namespace std;
int dp[1001][501];
int main()
{
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);

	if (k > (n + 1) / 2)
		k = n - k;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			dp[i][j] %= 10007;
		}
	}
	printf("%d\n", dp[n][k]);
	return 0;
}