#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int testcase = 0;
	for(int z=0;z<10;z++)
	{
		vector<pair<int, int>> score(101,pair<int,int>(0,0));
		scanf("%d", &testcase);
		for (int i = 0; i < 1000; i++)
		{
			int t = 0;
			scanf("%d", &t);
			score[t].first++;
			score[t].second = t;
		}

		sort(score.begin(), score.end());

		printf("#%d %d\n", testcase, score[100].second);
	}
	return 0;
}