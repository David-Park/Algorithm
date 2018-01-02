#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int d, rx, ry, bx, by;
};

char mat[10][11];
int srx, sry, sbx, sby;
int fx, fy;

int main()
{
	int n = 0, m = 0;
	queue<Node> q;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%s", &mat[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 'R')
			{
				srx = i;
				sry = j;
			}
			else if (mat[i][j] == 'B')
			{
				sbx = i;
				sby = j;
			}
			else if (mat[i][j] == 'O')
			{
				fx = i;
				fy = j;
			}
		}
	}

	q.push({ 0,srx,sry,sbx,sby });
	int ans = -1;
	while (!q.empty())
	{
		int cnt = q.front().d;
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		q.pop();

		if (cnt == 10)
			break;


	}

print:
	printf("%d\n", ans);
	return 0;
}