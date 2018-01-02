#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int solve(vector<int >ai, vector<int > bj, vector<int > tk, int a, int b)
{
	vector<pair<int, int> > adesk(ai.size(), pair<int, int>());
	vector<pair<int, int> > bdesk(bj.size(), pair<int, int>());
	for (int i = 0; i < tk.size(); i++)
	{

	}
}

int main()
{
	int testcase = 0;
	scanf("%d", &testcase);
	for (int tc = 1; tc <= testcase; tc++)
	{
		int N = 0, M = 0, K = 0;
		int a = 0, b = 0;
		int answer = 0;
		scanf("%d %d %d %d %d", &N, &M, &K, &a, &b);
		vector<int > ai(N, 0);
		vector<int > bj(M, 0);
		vector<int > tk(K, 0);
		for (int i = 0; i < N; i++)
			scanf("%d", &ai[i]);
		for (int i = 0; i < M; i++)
			scanf("%d", &bj[i]);
		for (int i = 0; i < K; i++)
			scanf("%d", &tk[i]);

		answer = solve(ai, bj, tk, a, b);

		printf("#%d %d\n", tc, answer);
	}
	return 0;
}