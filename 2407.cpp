#include <iostream>
using namespace std;

struct bigint {
	long long fst = 0;
	long long snd = 0;
	bigint operator +(const bigint &b)
	{
		bigint tmp;
		long long carry;
		tmp.snd = this->snd + b.snd;
		tmp.fst = this->fst + b.fst;

		//check carry
		carry = tmp.snd / 1000000000000000;//15 digit
		if (carry)
		{
			tmp.snd %= 1000000000000000;
			tmp.fst += carry;
		}

		return tmp;
	}
}typedef b_int;

b_int dp[101][51];
int main()
{
	int n = 0, m = 0, cnt = 0;
	scanf("%d %d", &n, &m);
	dp[1][0].snd = 1;
	dp[1][1].snd = 1;
	if (m > (n + 1) / 2)
		m = n - m;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0].snd = 1;
		for (int j = 1; j <= m; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}
	
	if (dp[n][m].fst == (long long)0)
		printf("%lld\n", dp[n][m].snd);
	else
	{
		printf("%lld", dp[n][m].fst);
		long long tmp = dp[n][m].snd;
		while (tmp > 0)
		{
			tmp /= 10;
			cnt++;
		}
		for (int i = cnt; i < 15; i++)
			printf("0");
		printf("%lld\n", dp[n][m].snd);
	}
	return 0;
}