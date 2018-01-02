#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	for (int z = 0; z < 10; z++)
	{
		int testcase = 0;
		vector<vector<int> > matrix(100, vector<int>(100, 0));
		vector<int> sum;
		scanf("%d", &testcase);
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				scanf("%d", &matrix[i][j]);

		for (int i = 0; i < 100; i++)
		{
			int t = 0;
			int t1 = 0;
			for (int j = 0; j < 100; j++)
			{
				t += matrix[i][j];
				t1 += matrix[j][i];
			}
			sum.push_back(t);
			sum.push_back(t1);
		}

		int cross = 0, cross1 = 0;
		for (int i = 0; i < 100; i++)
		{
			cross += matrix[i][i];
			cross1 += matrix[i][99 - i];
		}
		sum.push_back(cross);
		sum.push_back(cross1);

		sort(sum.begin(), sum.end());

		printf("#%d %d\n", z + 1, sum.back());
	}
	return 0;
}