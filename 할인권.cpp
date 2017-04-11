#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 1234567890
using namespace std;

void Dijkstra(vector<vector<int>> &adj, vector<vector<int>> &edge, vector<vector<int>> &dist, int n)
{
	for (int t = 1; t <= n; t++)
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		vector<bool> check(n + 1, true);
		int cnt = t - 1;

		//initialize
		for (int i = t; i <= n; i++)
		{
			i == t ? pq.push(pair<int, int>(0, i)) : pq.push(pair<int, int>(INF, i));
			check[i] = false;
		}

		while (cnt < n)
		{
			int now = pq.top().second, now_d = pq.top().first;
			pq.pop();
			if (check[now])
				continue;
			check[now] = true;
			dist[t][now] = now_d;
			dist[now][t] = now_d;
			cnt++;

			for (int i = 0; i < adj.at(now).size(); i++)
			{//update
				if (!check[adj.at(now).at(i)] && (dist[t][adj.at(now).at(i)] > now_d + edge[now][adj.at(now).at(i)]))
				{
					dist[t][adj.at(now).at(i)] = now_d + edge[now][adj.at(now).at(i)];
					pq.push(pair<int, int>(dist[t][adj.at(now).at(i)], adj.at(now).at(i)));
				}
			}
		}
	}
}

int main()
{
	int testcase = 0;
	scanf("%d", &testcase);

	for (int z = 1; z <= testcase; z++)
	{
		vector<vector<int>> adj;
		vector<vector<int>> e;
		vector<vector<int>> dist;
		int n = 0, m = 0, k = 0, p = 0;
		int ans = 0;
		scanf("%d %d %d", &n, &m, &k);
		adj.assign(n + 1, vector<int>());
		e.assign(n + 1, vector<int>(n + 1, INF));
		dist.assign(n + 1, vector<int>(n + 1, INF));
		for (int i = 0; i < m; i++)
		{
			int a = 0, b = 0, c = 0;
			scanf("%d %d %d", &a, &b, &c);
			e[a][b] = c;
			e[b][a] = c;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		Dijkstra(adj, e, dist, n);
		scanf("%d", &p);

		for (int i = 0; i < p; i++)
		{
			int start = 0, end = 0;
			scanf("%d %d", &start, &end);
			if (dist[start][end] > k)
				ans++;
		}
		printf("Case \#%d\n", z);
		printf("%d\n", ans);
	}
	return 0;
}