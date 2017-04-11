#include <iostream>
using namespace std;

long long dp[31];

int main()
{
	int n = 0;
	scanf("%d", &n);

	dp[0] = 1;
	dp[2] = 3;

	if (n % 2 == 1)
		printf("%d\n", 0);
	else
	{
		for (int i = 4; i <= n; i += 2)
		{
			dp[i] = dp[i - 2] * 3;
			for (int j = 4; j <= i; j += 2)
				dp[i] += dp[i - j] * 2;
		}

		printf("%lld\n", dp[n]);
	}
	return 0;
}