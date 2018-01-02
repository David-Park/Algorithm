#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dr_x[4] = { -1,0,1,0 };
int dr_y[4] = { 0,1,0,-1 };

int dfs(vector<vector<int > > m, vector<vector<int > > visited, int x, int y, int k, int N)
{
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dr_x[i];
		int next_y = y + dr_y[i];
		if (next_x <0 || next_x > N - 1 || next_y <0 || next_y>N - 1)
			continue;
		if (visited[next_x][next_y])
			continue;
		if (m[next_x][next_y] < m[x][y])
		{//regular path
			visited[next_x][next_y] = 1;
			result = max(result, dfs(m, visited, next_x, next_y, k, N));
			visited[next_x][next_y] = 0;
		}
		else if (k > 0 && m[next_x][next_y] < m[x][y] + k)
		{//cutting
			int tmp = m[next_x][next_y];
			m[next_x][next_y] = m[x][y] - 1;
			visited[next_x][next_y] = 1;
			result = max(result, dfs(m, visited, next_x, next_y, 0, N));
			m[next_x][next_y] = tmp;
			visited[next_x][next_y] = 0;
		}
	}

	return result + 1;
}

int main()
{
	int testcase = 0;
	scanf("%d", &testcase);

	for (int tc = 1; tc <= testcase; tc++)
	{
		int N = 0, K = 0, ind = 0;
		int answer = 0;
		scanf("%d %d", &N, &K);
		vector<vector<int > > map(N, vector<int >(N, 0));
		vector<vector<int> > visited = map;
		vector<queue<pair<int, int > > > index(21, queue<pair<int, int> >());
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
				index[map[i][j]].push(make_pair(i, j));
			}

		for (ind = 20; ind >= 0; ind--)
			if (!index[ind].empty())
				break;
		int tmp = index[ind].size();
		for (int i = 0; i < tmp; i++)
		{
			int x = index[ind].front().first, y = index[ind].front().second;
			index[ind].pop();
			visited[x][y] = 1;
			answer = max(dfs(map, visited, x, y, K, N), answer);
			visited[x][y] = 0;
		}

		printf("#%d %d\n", tc, answer);
	}
	return 0;
}