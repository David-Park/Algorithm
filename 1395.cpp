#include <iostream>
using namespace std;

struct Node
{
	int cnt = 0;
	int flg = 0;//1 or 0
};

Node tree[262145];

void update_range(int index, int start, int end, int left, int right, int flag)
{
	if (tree[index].flg != 0)
	{
		tree[index].cnt = (end - start + 1) - tree[index].cnt;
		if (start != end)
		{
			tree[index * 2].flg = (tree[index * 2].flg + 1) % 2;
			tree[index * 2 + 1].flg = (tree[index * 2 + 1].flg + 1) % 2;
		}
		tree[index].flg = 0;
	}

	if (end < left || right < start)
		return;
	if (left <= start && end <= right)
	{
		if(flag == 1)
			tree[index].cnt = (end - start + 1) - tree[index].cnt;
		if (start != end)
		{
			tree[index * 2].flg = (tree[index * 2].flg + 1) % 2;
			tree[index * 2 + 1].flg = (tree[index * 2 + 1].flg + 1) % 2;
		}
		return;
	}
	update_range(index * 2, start, (start + end) / 2, left, right, flag);
	update_range(index * 2 + 1, (start + end) / 2 + 1, end, left, right, flag);

	tree[index].cnt = tree[index * 2].cnt + tree[index * 2 + 1].cnt;
}

int cnt_switch(int index, int start, int end, int left, int right)
{
	if (tree[index].flg != 0)
	{
		tree[index].cnt = (end - start + 1) - tree[index].cnt;
		if (start != end)
		{
			tree[index * 2].flg = (tree[index * 2].flg + 1) % 2;
			tree[index * 2 + 1].flg = (tree[index * 2 + 1].flg + 1) % 2;
		}
		tree[index].flg = 0;
	}

	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index].cnt;

	return cnt_switch(index * 2, start, (start + end) / 2, left, right) + cnt_switch(index * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main()
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int o = 0, s = 0, t = 0;
		scanf("%d %d %d", &o, &s, &t);

		if (o == 0)
			update_range(1, 1, n, s, t, 1);
		else
			printf("%d\n", cnt_switch(1, 1, n, s, t));
	}
	return 0;
}