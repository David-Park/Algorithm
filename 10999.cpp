#include <iostream>
using namespace std;

//lazy propagation

struct Node
{
	long long sum = 0;
	long long lazy = 0;
};

Node BIT[3*1000010];
long long arr[1000010];

long long make_tree(int index, int start, int end)
{
	if (start == end)
	{
		return BIT[index].sum = arr[start];
	}
	else
	{
		int left = index * 2, right = index * 2 + 1;
		int mid = (start + end) / 2;
		return BIT[index].sum = make_tree(left, start, mid) + make_tree(right, mid + 1, end);
	}
}

void update_range(int index, int start, int end, int left, int right, long long lazy)
{
	if (BIT[index].lazy != 0)
	{
		BIT[index].sum += BIT[index].lazy *(end - start + 1);
		if (start != end)
		{//not leaf node
			BIT[index * 2].lazy += BIT[index].lazy;
			BIT[index * 2 + 1].lazy += BIT[index].lazy;
		}
		BIT[index].lazy = 0;
	}

	if (right < start || end < left)//out of range
		return;

	if (left <= start && end <= right)
	{
		BIT[index].sum += lazy*(end - start + 1);
		if (start != end)
		{
			BIT[index * 2].lazy += lazy;
			BIT[index * 2 + 1].lazy += lazy;
		}
		return;
	}
	update_range(index * 2, start, (start + end) / 2, left, right, lazy);
	update_range(index * 2 + 1, (start + end) / 2 + 1, end, left, right, lazy);

	BIT[index].sum = BIT[index * 2].sum + BIT[index * 2 + 1].sum;
}

long long sum(int index, int start, int end, int left, int right)
{
	if (BIT[index].lazy != 0)
	{
		BIT[index].sum += BIT[index].lazy * (end - start + 1);
		if (start != end)
		{
			BIT[index * 2].lazy += BIT[index].lazy;
			BIT[index * 2 + 1].lazy += BIT[index].lazy;
		}
		BIT[index].lazy = 0;
	}

	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return BIT[index].sum;

	return sum(index * 2, start, (start + end) / 2, left, right) + sum(index * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main()
{
	int n = 0, m = 0, k = 0;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);
	
	make_tree(1, 1, n);
	
	for (int z = 0; z < m + k; z++)
	{
		int a = 0, b = 0, c = 0;
		long long d = 0;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1)
		{
			scanf("%lld", &d);
			update_range(1, 1, n, b, c, d);
		}
		else
		{
			printf("%lld\n", sum(1, 1, n, b, c));
		}
	}
	return 0;
}