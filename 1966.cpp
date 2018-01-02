#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int testcase = 0;
	scanf("%d", &testcase);
	for(int z=0;z<testcase;z++)
	{
		int N = 0, M = 0, cnt = 0, x = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		scanf("%d %d", &N, &M);

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &x);
			q.push(pair<int, int>(x, i));
			pq.push(x);
		}

		while (!q.empty())
		{
			int priority = q.front().first;
			int idx = q.front().second;
			q.pop();
			if (pq.top() == priority)
			{
				cnt++;
				pq.pop();
				if (M == idx)
					break;
			}
			else
				q.push(pair<int, int>(priority, idx));
		}

		printf("%d\n", cnt);
	}
	return 0;
}