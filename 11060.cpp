#include <iostream>
#define INF 1234567890
using namespace std;

int dp[1001];
int a[1001];

int main()
{
	int n = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	fill(dp + 1, dp + n + 1, INF);
	dp[1] = 0;

	for (int i = 1; i < n; i++)
	{
		if (dp[i] == INF)
			continue;
		for (int j = i + 1; j <= n && j <= i + a[i]; j++)
		{
			if (dp[j] > dp[i] + 1)
				dp[j] = dp[i] + 1;
		}
	}
	if (dp[n] != INF)
		printf("%d\n", dp[n]);
	else
		printf("-1\n");
	return 0;
}