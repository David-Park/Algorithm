#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> mat;

int main()
{
	int n = 0, m = 0, k = 1;
	register int i = 0, j = 0;
	scanf("%d %d", &n, &m);

	mat.assign(n + 1, vector<long long>(n + 1, 0));
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &mat[i][j]);
			mat[i][j] += mat[i][j - 1];
		}
	}

	for (i = 0; i < m; i++)
	{
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		long long int res = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		for (j = x1; j <= x2; j++)
			res += mat[j][y2] - mat[j][y1 - 1];
		
		printf("%lld\n", res);
	}
	return 0;
}