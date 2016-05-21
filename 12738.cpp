#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> a[1000001];
int arr[1000001] = { 0, };
int ind[1000001] = { 0, };
int BIT[2000002] = { 0, };
int n;

void makeBIT()
{
	int lev = pow(2,(int)log2(n));
	int _index = 1;
	for (int i = lev; i < 2 * lev; i++)
		BIT[i] = ind[2 * (i - lev + 1)] < ind[2 * (i - lev + 1) + 1] ? ind[2 * (i - lev + 1) + 1] : ind[2 * (i - lev + 1)];

	for (int i = lev - 1; i >= 1; i--)
	{
		BIT[i] = BIT[2 * i] < BIT[2 * i + 1] ? BIT[2 * i + 1] : BIT[2 * i];
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <=n; i++)
	{
		scanf("%d", &arr[i]);
		a[i] = make_pair(arr[i], i);
	}

	sort(a+1,a+n+1);//nlogn

	for (int i = 1; i <= n; i++)
	{
		int max = 0;
		for (int j = 1; j < a[i].second; j++)
		{
			if (arr[j] < a[i].first && ind[j] > max)
				max = ind[j];
		}
		ind[a[i].second] = max + 1;
	}
	makeBIT();
	printf("%d\n", BIT[1]);
	return 0;
}