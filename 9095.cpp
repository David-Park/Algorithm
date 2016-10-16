#include <iostream>
using namespace std;

long long dp[11];
int main()
{
	int t = 0;
	cin >> t;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	for (int i = 0; i < t; i++)
	{
		int n = 0;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}