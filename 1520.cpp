#include <iostream>
#include <vector>
using namespace std;

int matrix[501][501];
int dp[502][502];

int vect_x[5] = { 0,0,1,0,-1 };
int vect_y[5] = { 0,1,0,-1,0 };
int dfs_dp(int now_x,int now_y, int n, int m)
{
	
	if (now_x == n && now_y == m)
		return dp[now_x][now_y] = 1;
	if (dp[now_x][now_y] != -1)
		return dp[now_x][now_y];

	dp[now_x][now_y] = 0;
	for (int i = 1; i <= 4; i++)
	{
		int next_x = now_x + vect_x[i];
		int next_y = now_y + vect_y[i];

		if (matrix[now_x][now_y] > matrix[next_x][next_y] && next_x > 0 && next_x <= n && next_y > 0 && next_y <= m)
		{
				dp[now_x][now_y] += dfs_dp(next_x, next_y, n, m);
		}
	}

	return dp[now_x][now_y];
}

int main()
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%d", &matrix[i][j]);

		fill(dp[i], dp[i] + m + 2, -1);
	}
	
	
	printf("%d\n", dfs_dp(1, 1, n, m));
	return 0;
}