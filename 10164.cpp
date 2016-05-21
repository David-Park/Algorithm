#include <iostream>
#include<cstdio>

long long comb(long long a, long long b)
{
	long long res = 1;
	for (long long i = a; i > b; i--)
		res *= i;
	for (long long i = a - b; i > 1; i--)
		res /= i;

	return res;
}

long long n, m, k,a,b, result;

int main()
{
	std::cin >> n >> m >> k;
	//(k-1)%n+1, k/n+1
	if (k == 0)
	{
		result = comb(n + m - 2, n - 1 < m - 1 ? m - 1 : n - 1);
	}
	else
	{
		a = (k - 1) / m;
		b = (k - 1) % m;
		result = comb(a + b, a < b ? b : a);
		result *= comb((n - 1 - a) + (m - 1 - b), (n - 1 - a) < (m - 1 - b) ? (m - 1 - b) : (n - 1 - a));
	}
	std::cout << result << std::endl;
	return 0;
}