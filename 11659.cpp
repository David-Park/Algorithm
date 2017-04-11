#include <iostream>
#include <vector>
#define INF 1234567890
using namespace std;

int main()
{
	int n = 0, m = 0;
	register int i = 0;
	vector<int> arr, dp;
	scanf("%d %d", &n, &m);
	arr.assign(n, 0);
	dp.assign(n, 0);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	dp[0] = arr[0];
	for (i = 1; i < n; i++)
		dp[i] = dp[i - 1] + arr[i];

	for (i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[b - 1] - dp[a - 1] + arr[a-1]);
	}
	return 0;
}