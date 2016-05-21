#include <iostream>
#include <cstdio>
using namespace std;

int n, ind = 1;

int comb(long long x, long long y)
{
	long long result = 1;
	for (long long i = 1; i<(y>x - y) ? x - y : y; i++)
		result *= x--;
	
	for (long long i = (y > x - y) ? x - y : y; i > 1; i--)
		result /= i;

	return (int)result;
}
int main()
{
	scanf("%d", &n);

	if (n == 0)
		printf("0\n");
	else if (n > 1024)
		printf("-1\n");
	else
	{
		while (n > comb(10, ind))
		{
			n -= comb(9, ind);
			ind++;
		}

		for (int i = -1; ind + i < 9; i++)
		{
			if (n - comb(ind + i, ind - 1) > 0)
			{
				n -= comb(ind + i, ind - 1);
			}

		}

	}
	return 0;
}