#include <iostream>
#include <vector>
using namespace std;

int dice[7];
int vect_x[5] = { 0,0,0,-1,1 };
int vect_y[5] = { 0,1,-1,0,0 };

void roll(vector<vector<int>> &map, int x, int y, int n, int m)
{
	if (map[x][y] == 0)
		map[x][y] = dice[6];
	else
	{
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
}

void redice(int com)
{
	int tmp = dice[1];
	switch (com)
	{
	case 1:
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = tmp;
		break;
	case 2:
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = tmp;
		break;
	case 3:
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = tmp;
		break;
	case 4:
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = tmp;
		break;
	default:
		break;
	}
}

bool isInRange(int x, int y, int n, int m)
{
	if (x > 0 && x <= n && y > 0 && y <= m)
		return true;
	else
		return false;
}

int main()
{
	int n = 0, m = 0, x = 0, y = 0, k = 0;
	vector<vector<int>> map;

	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	map.assign(n + 2, vector<int>(m + 2, -1));
	x++, y++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	
	for (int i = 1; i <= k; i++)
	{
		int com = 0;
		scanf("%d", &com);

		if (isInRange(x + vect_x[com], y + vect_y[com], n, m))
		{
			x += vect_x[com], y += vect_y[com];
			redice(com);
			roll(map, x, y, n, m);
			printf("%d\n", dice[1]);
		}
	}
	return 0;
}