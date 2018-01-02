#include <cstdio>
int N;
int result;
int Map[20][20] = {};
bool visited[101];

void visitclear()
{
	for (int i = 0; i < 101; i++)
		visited[i] = false;
}

void init()
{
	visitclear();
	result = -1;
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int a = 1; a < N; a++)
			{
				for (int b = 1; b < N; b++)
				{
					if (j + a <= N - 1 &&
						i + a + b <= N - 1 &&
						j - b >= 0 &&
						2 * (a + b) > result)
					{
						visitclear();
						bool flag = true;
						for (int k = 0; k < a; k++)
						{
							if (visited[Map[i + k][j + k]])
							{
								flag = false;
								break;
							}
							visited[Map[i + k][j + k]] = true;
						}
						if (!flag)
							continue;
						for (int k = 0; k < b; k++)
						{
							if (visited[Map[i + a + k][j + a - k]])
							{
								flag = false;
								break;
							}
							visited[Map[i + a + k][j + a - k]] = true;
						}
						if (!flag)
							continue;
						for(int k=0;k<a;k++)
						{
							if (visited[Map[i + a + b - k][j + a - b - k]])
							{
								flag = false;
								break;
							}
							visited[Map[i + a + b - k][j + a - b - k]] = true;
						}
						if (!flag)
							continue;
						for (int k = 0; k < b; k++)
						{
							if (visited[Map[i + b - k][j - b + k]])
							{
								flag = false;
								break;
							}
							visited[Map[i + b - k][j - b + k]] = true;
						}
						if (!flag)
							continue;
						
						result = 2 * (a + b);
					}
				}
			}
		}
	}
}
int main()
{
	int testcase;
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++)
	{
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				scanf("%d", &Map[j][k]);
		init();
		solve();
		printf("#%d %d\n", i, result);
	}
	return 0;
}