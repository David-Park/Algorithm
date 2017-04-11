#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001][2];
int main()
{
	int n = 0;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	
	dp[1][0] = -1001;
	dp[1][1] = arr[1];
	
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] < dp[i-1][1] ? dp[i-1][1] : dp[i - 1][0];
		dp[i][1] = dp[i - 1][1] + arr[i] < arr[i] ? arr[i] : dp[i - 1][1] + arr[i];
	}
	
	
	printf("%d\n", max(dp[n][0],dp[n][1]));
	return 0;
}