#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	for (int z = 0; z < 10; z++)
	{
		int length = 0;
		int answer = 0;
		scanf("%d", &length);
		vector<int> building(length, 0);
		
		for (int i = 0; i < length; i++)
			scanf("%d", &building[i]);

		for (int i = 2; i < length - 2; i++)
		{
			if (building[i - 2] > building[i] || building[i - 1] > building[i] || building[i + 1] > building[i] || building[i + 2] > building[i])
				continue;
			else
			{
				answer += building[i] - max(building[i - 2], max(building[i - 1], max(building[i + 1], building[i + 2])));
			}
		}

		printf("#%d %d\n", z + 1, answer);
	}
	return 0;
}