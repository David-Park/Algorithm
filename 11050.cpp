#include <iostream>
using namespace std;

int bin_coef(int n, int k)
{
	if (n == k || k == 0)
		return 1;
	else if (k == 1)
		return n;
	else
	{
		if (k > (n + 1) / 2)
			k = n - k;
		return bin_coef(n - 1, k) + bin_coef(n - 1, k - 1);
	}
}

int main()
{
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);
	printf("%d\n", bin_coef(n, k));
	return 0;
}