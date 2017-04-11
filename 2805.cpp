#include <iostream>
using namespace std;

long long a[1000001];

int main()
{
	int n = 0;
	long long m = 0;
	long long min = 0, max = 0, mid = 0;
	scanf("%d %lld", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		if (max < a[i])
			max = a[i];
	}

	while (min <= max)
	{
		long long rest = 0;
		mid = (min + max) / 2;

		for (int i = 0; i < n; i++)
			a[i] - mid > 0 ? rest += a[i] - mid : rest;

		if (rest < m)
			max = mid - 1;
		else
			min = mid + 1;
	}

	printf("%lld\n", min - 1);
	return 0;
}