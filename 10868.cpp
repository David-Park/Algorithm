#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#define INF 1234567890
using namespace std;

vector<int> arr;
vector<int> tree;

int make_tree(int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = min(make_tree(node * 2, start, (start + end) / 2), make_tree(node * 2 + 1, (start + end) / 2 + 1, end));
}

int search_tree(int now, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return INF;
	if (left <= start && end <= right)
		return tree[now];
	return min(search_tree(now * 2, start, (start + end) / 2, left, right), search_tree(now * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main()
{
	int n = 0, m = 0;
	int k = 0;
	scanf("%d %d", &n, &m);

	while ((n >> k++));

	arr.assign(n + 1, INF);
	tree.assign((1<<k), INF);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	make_tree(1, 1, n);

	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		printf("%d\n", search_tree(1, 1, n, a, b));
	}
	return 0;
}