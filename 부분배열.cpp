#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);

	for (int z = 0; z < t; z++)
	{
		vector<int> a, res;
		int t = 0, n = 0, s = 0, cnt = 0;
		scanf("%d %d", &n, &s);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &t);
			a.push_back(t);
		}
		t = 0;
		for (int i = 0; i < n; i++)
		{
			t += a.at(i);
			cnt++;
			while (t >= s)
			{
				res.push_back(cnt);
				t -= a.at(i - cnt + 1);
				cnt--;
			}
		}
		if (cnt == n)
			res.push_back(0);
		t = res.front();
		for (int i = 1; i < res.size(); i++)
			if (t > res.at(i))
				t = res.at(i);
		printf("#testcase%d\n", z + 1);
		printf("%d\n", t);
	}
	return 0;
}