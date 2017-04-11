#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a(1011,0);
vector<int> dp(1011, 0);
vector<int> dp1(1011, 0);//inc
vector<int> dp2(1011, 0);//inv_inc

int main()
{
	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	dp1[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp1[i] = 1;//inc
		for (int j = 1; j < i; j++)
		{//inc
			if (a[i] > a[j] && dp1[i] < dp1[j] + 1)
				dp1[i] = dp1[j] + 1;
		}
	}
	dp2[n] = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		dp2[i] = 1;//inv_inc
		for (int j = n; j > 1; j--)
		{//inv_inc
			if (a[i] > a[j] && dp2[i] < dp2[j] + 1)
				dp2[i] = dp2[j] + 1;
		}
	}
	for (int i = 1; i <= n; i++)
		dp[i] = dp1[i] + dp2[i];
	sort(dp.begin() + 1, dp.begin() + n + 1);
	cout << dp[n] - 1 << endl;
	return 0;
}