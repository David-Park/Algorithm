#include<iostream>
#include <vector>
#include <cstdio>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main()
{
	int T = 0;

	scanf("%d", &T);
	for (int z = 0; z < T; z++)
	{
		int N;
		scanf("%d", &N);

		vector<vector<int> > snail(N, vector<int>(N, 0));
		int cnt = 2;
		int i = 0, j = 0;
		snail[i][j] = 1;
		while (cnt<=N*N)
		{
			for (int k = 0; k < 4; k++)
			{
				while ((0 <= i + dx[k] && i + dx[k] < N) && (0 <= j + dy[k] && j + dy[k] < N) && snail[i + dx[k]][j + dy[k]] == 0)
				{
					snail[(i += dx[k])][(j += dy[k])] = cnt++;
				}
			}
		}

		printf("#%d\n", z + 1);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				printf("%d ", snail[i][j]);
			printf("\n");
		}
	}
	return 0;
}