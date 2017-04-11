#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 1234567890
using namespace std;


void Dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int s, int n)
{
	vector<bool> check(n + 1, false);
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	for (int i = 0; i < adj[s].size(); i++)
		pq.push(adj[s][i]);

	dist[s] = 0;
	pq.push(pair<int, int>(dist[s], s));
	
	while (!pq.empty())
	{
		int now = pq.top().second, cost = pq.top().first;
		pq.pop();

		if (check[now])
			continue;
		
		check[now] = true;

		for (int i = 0; i < adj[now].size(); i++) //update
			if (!check[adj[now][i].second] && dist[adj[now][i].second] > cost + adj[now][i].first)
			{
				dist[adj[now][i].second] = cost + adj[now][i].first;
				pq.push(pair<int,int>(dist[adj[now][i].second], adj[now][i].second));
			}
	}
}

int main()
{
	int n = 0, m = 0;
	int start = 0;
	vector<vector<pair<int,int>>> adj;
	vector<int> dist;
	scanf("%d %d %d", &n, &m, &start);
	adj.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, INF);

	for (int i = 1; i <= m; i++)
	{
		int u = 0, v = 0, w = 0;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(pair<int, int>(w, v));
	}
	Dijkstra(adj, dist, start, n);

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}