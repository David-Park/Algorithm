#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n = 0, idx = 0;
	stack<int> stk;
	vector<int> arr;
	vector<char> ret;
	scanf("%d", &n);
	arr.assign(n, 0);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)
	{
		stk.push(i);
		ret.push_back('+');

		while (!stk.empty() && stk.top() == arr[idx])
		{
			stk.pop();
			ret.push_back('-');
			idx++;
		}
	}

	if (!stk.empty())
		printf("NO\n");
	else
		for (int i = 0; i < ret.size(); i++)
			printf("%c\n", ret[i]);

	return 0;
}