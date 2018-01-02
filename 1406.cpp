#include <iostream>
#include <stack>
#include <string>
using namespace std;

class editor
{
	stack<char> left, right;
public:
	editor(string s)
	{
		for (int i = 0; i < s.length(); i++)
			left.push(s[i]);
	}

	void command()
	{
		char a;
		cin >> a;
		switch (a)
		{
		case 'L':
			command_L();
			break;
		case 'D':
			command_D();
			break;
		case 'B':
			command_B();
			break;
		case 'P':
			command_P();
			break;
		}
	}
	void command_L()
	{
		if (!left.empty())
		{
			right.push(left.top());
			left.pop();
		}
	}
	void command_D()
	{
		if (!right.empty())
		{
			left.push(right.top());
			right.pop();
		}
	}
	void command_B()
	{
		if (!left.empty())
			left.pop();
	}
	void command_P()
	{
		char x;
		cin >> x;
		left.push(x);
	}
	void print_editor()
	{
		while(!left.empty())
		{
			right.push(left.top());
			left.pop();
		}

		while(!right.empty())
		{
			cout << right.top();
			right.pop();
		}
		cout << "\n";
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	string str;
	int n = 0;
	cin >> str >> n;
	editor e(str);

	for (int i = 0; i < n; i++)
	{
		e.command();
	}
	e.print_editor();

	return 0;
}