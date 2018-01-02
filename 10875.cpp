#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1234567890
using namespace std;

struct Line
{
	int x1, x2, y1, y2;
	int dir;
	Line(int x1, int x2, int y1, int y2):x1(x1),x2(x2),y1(y1),y2(y2)
	{
		if (x1 == x2)//shape |
			dir = 0;
		if (y1 == y2)//shape -
			dir = 1;

		setpoint();
	}
	void setpoint()
	{
		if (x1 > x2)//2 is bigger
			swap(x1, x2);
		if (y1 > y2)//2 is bigger
			swap(y1, y2);
	}
};

vector<Line> line;
pair<int, int> t[1001];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	int n = 0, L = 0;
	scanf("%d %d", &L, &n);

	for (int i = 0; i < n; i++)
	{
		char tmp[2];
		scanf("%d %s", &t[i].first, &tmp);
		if (tmp[0] == 'L')
			t[i].second = 1;
		else
			t[i].second = 3;
	}

	t[n] = make_pair(INF, 1);
	//out line
	line.push_back(Line(-L - 1, -L - 1, L + 1, -L - 1));
	line.push_back(Line(-L - 1, L + 1, -L - 1, -L - 1));
	line.push_back(Line(L + 1, L + 1, -L - 1, L + 1));
	line.push_back(Line(-L - 1, L + 1, L + 1, L + 1));
	
	int x = 0, y = 0, dir = 0;//now position
	long long ans = 0;
	for (int i = 0; i <= n; i++)
	{
		int t_p = INF;
		for (int j = 0; j < line.size(); j++)
		{
			if (line[j].dir == 0)//shape |
			{
				if (dir == 0)
				{
					if (line[j].y1 <= y && y <= line[j].y2 && x < line[j].x1)
						t_p = min(t_p, line[j].x1 - x);
				}
				else if (dir == 1)
				{
					if (x == line[j].x1 && y < line[j].y1)
						t_p = min(t_p, line[j].y1 - y);
				}
				else if (dir == 2)
				{
					if (line[j].y1 <= y && y <= line[j].y2 && line[j].x1 < x)
						t_p = min(t_p, x - line[j].x1);
				}
				else
				{
					if (x == line[j].x1 && line[j].y2 < y)
						t_p = min(t_p, y - line[j].y2);
				}
			}
			else//shape -
			{
				if (dir == 0)
				{
					if (y == line[j].y1 && x < line[j].x1)
						t_p = min(t_p, line[j].x1 - x);
				}
				else if (dir == 1)
				{
					if (line[j].x1 <= x && x <= line[j].x2 && y < line[j].y1)
						t_p = min(t_p, line[j].y1 - y);
				}
				else if (dir == 2)
				{
					if (y == line[j].y1 && line[j].x2 < x)
						t_p = min(t_p, x - line[j].x2);
				}
				else
				{
					if (line[j].x1 <= x && x <= line[j].x2 && line[j].y1 < y)
						t_p = min(t_p, y - line[j].y1);
				}
			}
		}
		if (t_p <= t[i].first)
		{
			printf("%lld\n", ans + t_p);
			return 0;
		}

		ans += t[i].first;
		
		int nx = x + dx[dir] * t[i].first;
		int ny = y + dy[dir] * t[i].first;
		line.push_back(Line(x, nx, y, ny));
		dir = (dir + t[i].second) % 4;
		x = nx;
		y = ny;
	}
	return 0;
}