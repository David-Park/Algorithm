#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	string str;
	stack<char> st;
	int res = 0, b_cnt = 0;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			st.push(str[i]);
		}
		else// ')'
		{
			if (str[i - 1] == '(')
			{//laser
				st.pop();
				res += st.size();
			}
			else
			{
				res ++;
				st.pop();
			}
		}
	}
	cout << res << "\n";
	return 0;
}