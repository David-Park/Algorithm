#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

bool edge[1001][1001];

void dfs(int v, int n)
{
	vector<bool> visited(n + 1, false);
	stack<int> st;
	st.push(v);

	while (!st.empty())
	{
		int now = st.top();
		st.pop();

		if (visited[now])
			continue;

		printf("%d ", now);
		visited[now] = true;

		for (int i = n; i >= 1; i--)
			if (!visited[i] && edge[now][i])
				st.push(i);

	}
	printf("\n");
}

void bfs(int v, int n)
{
	vector<bool> visited(n + 1, false);
	queue<int> q;
	q.push(v);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (visited[now])
			continue;

		printf("%d ", now);
		visited[now] = true;

		for (int i = 1; i <= n; i++)
			if (!visited[i] && edge[now][i])
				q.push(i);
	}
	printf("\n");
}

int main()
{
	int n = 0, m = 0, v = 0;
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++)
	{
		int s = 0, e = 0;
		scanf("%d %d", &s, &e);
		edge[s][e] = true;
		edge[e][s] = true;
	}
	
	dfs(v, n);
	bfs(v, n);

	return 0;
}