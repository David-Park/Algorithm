#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

void rotate_left(deque<int> &dq)
{
	int tmp = dq.front();
	dq.pop_front();
	dq.push_back(tmp);
}
void rotate_right(deque<int> &dq)
{
	int tmp = dq.back();
	dq.pop_back();
	dq.push_front(tmp);
}

int main()
{
	int N = 0, M = 0, ret = 0;
	deque<int> dq;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		dq.push_back(i);
	for (int i = 1; i <= M; i++)
	{
		int idx = 0, tmp = 0;
		cin >> idx;
		tmp = (int)(find(dq.begin(), dq.end(), idx) - dq.begin()) + 1;
		if (tmp <= (dq.size() + 1) / 2)
		{
			while (tmp-- > 1)
			{
				rotate_left(dq);
				ret++;
			}
		}
		else
		{
			tmp = dq.size() - tmp + 1;
			while (tmp-- >= 1)
			{
				rotate_right(dq);
				ret++;
			}
		}
		dq.pop_front();
	}

	cout << ret << '\n';
	return 0;
}