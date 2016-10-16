#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int dst;
	int cst;

	bool operator < (const struct Edge &other) const{
		return this->cst > other.cst; 
	}
};
vector<Edge> G[1001];
priority_queue<Edge> q;
bool visited[1001];
priority_queue<int> dist[1001];

int main()
{
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++)
	{//make Graph G
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back(Edge{ b,c });
	}

	q.push(Edge{ 1,0 });
	dist[1].push(0);
	while (!q.empty())
	{
		Edge now = q.top();
		q.pop();

		int n_vtx = now.dst;
		int n_cst = now.cst;
		for (int i = 0; i < G[n_vtx].size(); i++)
		{
			int v = G[n_vtx][i].dst;
			if (dist[v].size() < k || dist[v].top() > G[n_vtx][i].cst + n_cst)
			{
				if (dist[v].size() == k)
					dist[v].pop();

				dist[v].push(n_cst + G[n_vtx][i].cst);//save dist
				q.push(Edge{ v,G[n_vtx][i].cst + n_cst });
			}

		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[i].size() < k)
			cout << -1 << endl;
		else
			cout << dist[i].top() << endl;
	}
	return 0;
}