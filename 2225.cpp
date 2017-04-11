#include <iostream>
#define DIV 1000000000
using namespace std;

long long dp[201][201];

int main()
{
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);
	
	for (int i = 1; i <= k; i++)
	{
		dp[0][i] = 1;
		dp[i][1] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % DIV;
		}
	}

	printf("%lld\n", dp[n][k]);
	return 0;
}