#include <iostream>
#include <cstring>
using namespace std;

int dp[5001] = { 1 };
char str[5001];

int main()
{
	std::ios::sync_with_stdio(false);
	int len = 0;
	scanf("%s",str);
	len = strlen(str);

	if (str[0] == '0')
		dp[0] = 0;
	if (str[1] == '0')
	{
		dp[1] = 1;
	}
	else if (str[0] == '1' || (str[0] == '2'&&str[1] - '0' < 7))
		dp[1] = 2;
	else
		dp[1] = 1;

	for (int i = 2; i < len; i++)
	{
		if (str[i] == '0')
		{
			dp[i] = dp[i - 2];
		}
		else if (str[i - 1] == '1' || (str[i - 1] == '2'&&str[i] - '0' < 7))
			dp[i] = (dp[i - 2] + dp[i - 1])%1000000;
		else
			dp[i] = dp[i - 1];
	}

	printf("%d\n",dp[len - 1]);
}