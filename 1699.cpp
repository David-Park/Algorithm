#include <iostream>
#include <algorithm>
#include <math.h>
#define MAX 1234567890
using namespace std;

int dp[100001];

int main()
{
	int n = 0, res = 0;
	scanf("%d", &n);
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = MAX;

		for (int j = 1; j*j <= i; j++)
			dp[i] = min(dp[i], dp[i - j*j] + 1);

	}

	printf("%d\n", dp[n]);
	return 0;
}