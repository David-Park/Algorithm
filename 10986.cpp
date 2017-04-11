#include <iostream>
using namespace std;

int arr[1000001];
int dp[1000001];
long long k[1000] = {0,};

int main()
{
	int n = 0, m = 0;
	long long res = 0;
	register int i = 0, j = 0;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	dp[0] = 0;
	for (i = 1; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + arr[i]) % m;
	}

	for (i = 0; i <= n; i++)
	{
		k[dp[i]]++;
	}

	for (i = 0; i < m; i++)
		res += (k[i] * (k[i] - 1)) / 2;
	printf("%lld\n", res);
	return 0;
}