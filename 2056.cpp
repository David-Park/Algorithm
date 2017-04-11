#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr[10001];
int cost[10001];
int maximum;
int main()
{
	int n = 0;
	scanf("%d", &n);

	for (int z = 1; z <= n; z++)
	{
		int cnt = 0;
		scanf("%d %d", &cost[z], &cnt);

		for (int i = 0; i < cnt; i++)
		{
			int _index = 0;
			scanf("%d", &_index);
			arr[z].push_back(_index);
		}
	}

	for (int z = 1; z <= n; z++)
	{
		if (!arr[z].empty())
		{
			int tmp = cost[arr[z][0]];
			for (int i = 1; i < arr[z].size(); i++)
				tmp = max(tmp, cost[arr[z][i]]);

			cost[z] += tmp;
		}
		maximum = max(cost[z], maximum);
	}

	printf("%d\n", maximum);
	return 0;
}