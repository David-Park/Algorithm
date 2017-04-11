#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr;
vector<long long> tree;//BIT

void update(int size, int index, long long value)
{
	while (index <= size)
	{
		tree[index] += value;
		index += (index&-index);
	}
}

long long sum(int size, int index)
{
	long long ret = 0;
	while (index > 0)
	{
		ret += tree[index];
		index -= (index&-index);
	}
	return ret;
}

int main()
{
	int n = 0, m = 0, k = 0;
	scanf("%d %d %d", &n, &m, &k);
	arr.assign(n + 1, 0);
	tree.assign(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
		update(n, i, arr[i]);
	}

	for (int i = 0; i < m + k; i++)
	{
		int a = 0, b = 0, c = 0;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1)
		{//update
			update(n, b, (long long)c - arr[b]);
			arr[b] = (long long)c;
		}
		else
		{//sum
			printf("%lld\n", sum(n, c) - sum(n, b - 1));
		}
	}
	return 0;
}