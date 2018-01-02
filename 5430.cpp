#include <iostream>
#include <deque>
#include <string>
using namespace std;

void tokenizer(deque<int> &dq, string str)
{
	int str_len = str.length();
	for (int pos = 1; pos < str_len;)
	{
		int next = str.find_first_of(",]", pos);
		string sub = str.substr(pos,  next - pos);
		dq.push_back(stoi(sub));
		pos = next + 1;
	}
}
void print(deque<int> &dq, bool reverse)
{
	cout << "[";
	if (reverse)
	{
		if (!dq.empty())
		{
			cout << dq.back();
			dq.pop_back();
		}
		while (!dq.empty())
		{
			cout << "," << dq.back();
			dq.pop_back();
		}
	}
	else
	{
		if (!dq.empty())
		{
			cout << dq.front();
			dq.pop_front();
		}
		while (!dq.empty())
		{
			cout << "," << dq.front();
			dq.pop_front();
		}
	}
	cout << "]\n";
}

int main()
{
	iostream::ios_base::sync_with_stdio(false);
	int T = 0;
	cin >> T;
	for (int z = 0; z < T; z++)
	{
		deque<int> dq, tmp;
		int n = 0, com_len = 0;
		bool reverse = false;
		bool flg = true;
		string arr, com;
		cin >> com;
		cin >> n;
		cin >> arr;

		if(n > 0)
			tokenizer(dq, arr);

		com_len = com.length();
		for (int i = 0; flg && i < com_len; i++)
		{
			switch (com[i])
			{
			case 'R':
				reverse = !reverse;
				break;
			case 'D':
				if (dq.empty())
					flg = false;
				else
					if (reverse)
						dq.pop_back();
					else
						dq.pop_front();
				break;
			}
		}
		if (flg)
			print(dq, reverse);
		else
			cout << "error\n";
	}
	return 0;
}