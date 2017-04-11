#include <iostream>
using namespace std;

int dp[101];
int main()
{
	int N = 0;

	dp[1] = 1;
	for (int i = 1; i <= 100; i++)
		dp[i] = dp[i - 1] + i*i;
	while (1)
	{
		cin >> N;
		if (N == 0)break;
		cout << dp[N] << endl;
	}
	return 0;
}