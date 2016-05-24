#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main()
{
	int v_cnt = 0, e_cnt = 0;
	int s = 0, d = 0;
	int result = 0;
	queue<int> q;
	vector<bool> isvisited;
	vector< list<int> > g;
	scanf("%d %d", &v_cnt, &e_cnt);
	g.resize(v_cnt);
	isvisited.resize(v_cnt, false);
	for (int i = 0; i < e_cnt; i++)
	{
		scanf("%d %d", &s, &d);
		g[s - 1].push_back(d - 1);
		g[d - 1].push_back(s - 1);
	}
	q.push(0);
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		if (isvisited[s])
			continue;

		for (list<int>::iterator i = g[s].begin(); i != g[s].end(); i++)
			if(!isvisited[*i])
				q.push(*i);

		isvisited[s] = true;
		result++;
	}

	printf("%d\n", result - 1);
	return 0;
}