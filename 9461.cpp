#include <iostream>
using namespace std;

long long dp[101] = {0,1,1,1,2,2,3,4,5,7,9,};

int main()
{
	int t = 0, n = 0;
	scanf("%d", &t);

	for (int i = 11; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	for (int z = 0; z < t; z++)
	{
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}