#include <iostream>
#include <algorithm>
using namespace std;

int arr[1100];
int dp[1100];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];

	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
	}

	sort(dp + 1, dp + n + 1);
	cout << dp[n];
	return 0;
}