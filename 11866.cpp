#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N = 0, M = 0;
	queue<int> q;
	vector<int> ret;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		q.push(i);
	
	while (!q.empty())
	{
		for (int i = 1; i < M; i++)
		{
			q.push(q.front());
			q.pop();
		}
		ret.push_back(q.front());
		q.pop();
	}
	printf("<%d", ret.front());
	for (vector<int>::iterator i = ret.begin() + 1; i != ret.end(); i++)
		printf(", %d", *i);
	printf(">\n");

	return 0;
}