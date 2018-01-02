#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		stack<char> st;
		bool chk = false;
		char str[55] = "";
		scanf("%s", str);

		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] == '(')
				st.push(str[j]);
			else if (str[j] == ')')
			{
				if (st.empty())
				{
					printf("NO\n");
					chk = true;
					break;
				}
				else
					st.pop();
			}
		}

		if (chk)
			continue;

		if (!st.empty())
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}