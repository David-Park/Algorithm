#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;

vector<int> path;
pair<int, int> pos[1001];
pair<int, int> pos2[1001];
int dp[1001][1001];
int N = 0, W = 0;
int ans = 0;

int dist(int n1, int n2)
{
	if (n1 == W || n2 == W)
		return 0;
	int &ret = dp[n1][n2];
	if (ret != -1)
		return ret;

	ret = MAX;
	int nxt = max(n1, n2) + 1;
	int _n1 = dist(nxt, n2) +abs(pos[n1].first - pos[nxt].first) + abs(pos[n1].second - pos[nxt].second);
	int _n2 = dist(n1, nxt) +abs(pos2[n2].first - pos2[nxt].first) + abs(pos2[n2].second - pos2[nxt].second);
	ret = min(_n1, _n2);
	return ret;
}

void trace_path(int n1, int n2)
{
	if (n1 == W || n2 == W)
	{
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << endl;
		return;
	}

	int nxt = max(n1, n2) + 1;
	int _n1 = dp[nxt][n2] + abs(pos[n1].first - pos[nxt].first) + abs(pos[n1].second - pos[nxt].second);
	int _n2 = dp[n1][nxt] + abs(pos2[n2].first - pos2[nxt].first) + abs(pos2[n2].second - pos2[nxt].second);
	if (_n1 < _n2)
	{
		path.push_back(1);
		trace_path(nxt, n2);
	}
	else
	{
		path.push_back(2);
		trace_path(n1, nxt);
	}

	return;
}

int main()
{
	cin >> N >> W;
	pair<int, int> n1 = { 0,0 }, n2 = { N,N };

	for (int i = 1; i <= W;i++)
		cin >> pos[i].first >> pos[i].second;
	pos[0].first = pos[0].second = 1;
	pos2[0].first = pos2[0].second = N;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= W;i++)
		pos2[i] = pos[i];


	cout << dist(0, 0) << endl;
	trace_path(0, 0);

	return 0;
}