#include <iostream>
using namespace std;

/*
나머지 연산에서 페르마의 소정리를 활용한 곱셈의 역원 찾기를 이용해 품
*/
long long power(long long x, long long y, long long m)
{
	long long ret = 1;
	while (y > 0) {
		if (y % 2 != 0)
		{
			ret *= x;
			ret %= m;
		}
		x *= x;
		x %= m;
		y = y >> 1;
	}
	return ret;
}

int main()
{
	long long n = 0, k = 0, p = 1000000007;
	long long a = 1, b = 1, c = 1;
	long long ans = 1;
	cin >> n >> k;

	for (long long i = 2; i <= n; i++)
	{
		a *= i;
		a %= p;
	}

	for (long long i = 2; i <= k; i++)
	{
		b *= i;
		b %= p;
	}

	for (long long i = 2; i <= n - k; i++)
	{
		b *= i;
		b %= p;
	}
	c = power(b, p - 2, p);
	ans = a*c;
	ans %= p;
	cout << ans << "\n";
	return 0;
}