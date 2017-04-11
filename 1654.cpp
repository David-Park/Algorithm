#include <iostream>
using namespace std;

long long a[10001];

int main()
{
	int n = 0, m = 0;
	long long s = 1, e = 0, mid = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		if (e < a[i])
			e = a[i];
	}

	while (s <= e)
	{
		int cnt = 0;
		mid = (s + e) / 2;
		
		for (int i = 0; i < n; i++)
			cnt += (a[i] / mid);

		if (cnt < m)
			e = mid - 1;
		else
			s = mid + 1;
	}

	printf("%lld\n", s - 1);
	return 0;
}