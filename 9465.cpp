#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

unsigned int dp[100001][3];
int arr[2][100001];

int main()
{
	int t = 0;
	scanf("%d", &t);
	
	for (int z = 0; z < t; z++)
	{
		int n = 0;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[0][i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[1][i]);

		dp[1][0] = 0;
		dp[1][1] = arr[0][1];
		dp[1][2] = arr[1][1];

		for (int i = 2; i <= n; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][0] = max(dp[i][0], dp[i - 1][2]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[0][i];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[1][i];
		}
		unsigned int ans = max(dp[n][1], dp[n][2]);
		ans = max(dp[n][0], ans);
		printf("%d\n", ans);
	}
	return 0;
}