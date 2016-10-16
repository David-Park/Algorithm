#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[j] >= dp[i])
				dp[i] = dp[j] + 1;
		}
	}

	sort(dp + 1, dp + n + 1);
	int ans = dp[n];
	cout << ans << endl;
	return 0;
}