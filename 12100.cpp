#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int> >  map;

map a;
vector<map> dp;
int ans = 0;

int find_max(int n, int depth)
{
	int max = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (max < dp[depth][i][j])
				max = dp[depth][i][j];
	return max;
}

void dfs(int n, int depth, int cnt)
{
	if (depth == cnt)
	{
		int tmp = find_max(n, depth);
		if (ans < tmp)
			ans = tmp;
	}
	else
	{
		queue<int> q;
		//up
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				if (dp[depth][j][i] != 0)
					q.push(dp[depth][j][i]);

			for (int j = 1; j <= n; j++)
			{
				if (!q.empty())
				{
					dp[depth + 1][j][i] = q.front();
					q.pop();

					if (!q.empty() && dp[depth + 1][j][i] == q.front())
					{//same number
						dp[depth + 1][j][i] += q.front();
						q.pop();
					}
				}
				else
					dp[depth + 1][j][i] = 0;
			}
		}
		dfs(n, depth + 1, cnt);

		//down
		for (int i = 1; i <= n; i++)
		{
			for (int j = n; j >= 1; j--)
				if (dp[depth][j][i] != 0)
					q.push(dp[depth][j][i]);

			
			for (int j = n; j >= 1; j--)
			{
				if (!q.empty())
				{
					dp[depth + 1][j][i] = q.front();
					q.pop();

					if (!q.empty() && dp[depth + 1][j][i] == q.front())
					{//same number
						dp[depth + 1][j][i] += q.front();
						q.pop();
					}
				}
				else
					dp[depth + 1][j][i] = 0;
			}
		}
		dfs(n, depth + 1, cnt);

		//left
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				if (dp[depth][i][j] != 0)
						q.push(dp[depth][i][j]);

			for (int j = 1; j <= n; j++)
			{
				if (!q.empty())
				{
					dp[depth + 1][i][j] = q.front();
					q.pop();
					
					if (!q.empty() && dp[depth + 1][i][j] == q.front())
					{//same number
						dp[depth + 1][i][j] += q.front();
						q.pop();
					}
				}
				else
					dp[depth + 1][i][j] = 0;
			}
		}
		dfs(n, depth + 1, cnt);

		//right
		for (int i = 1; i <= n; i++)
		{
			for (int j = n; j >= 1; j--)
				if (dp[depth][i][j] != 0)
					q.push(dp[depth][i][j]);
			
			for (int j = n; j >= 1; j--)
			{
				if (!q.empty())
				{
					dp[depth + 1][i][j] = q.front();
					q.pop();
					
					if (!q.empty() && dp[depth + 1][i][j] == q.front())
					{//same number
						dp[depth + 1][i][j] += q.front();
						q.pop();
					}
				}
				else
					dp[depth + 1][i][j] = 0;
			}
		}
		dfs(n, depth + 1, cnt);
	}
}

int main()
{
	int n = 0, cnt = 10;
	scanf("%d", &n);
	a.assign(n + 2, vector<int>(n + 2, 0));
	dp.assign(cnt + 1, a);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	dp[0] = a;
	dfs(n, 0, cnt);
	printf("%d\n", ans);
	return 0;
}