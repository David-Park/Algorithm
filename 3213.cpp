#include <iostream>
using namespace std;

int cnt[3] = { 0,0,0 };

int main()
{
	int n = 0;
	char str[5];
	int sub1 = 0, sub2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str[0] == '1')
		{
			if (str[2] == '4')
			{// 1/4
				cnt[0]++;
			}
			else
			{// 1/2
				cnt[1]++;
			}
		}
		else
		{// 3/4
			cnt[2]++;
		}
	}

	if (cnt[2] >= cnt[0])
	{
		sub1 = cnt[2];
		sub2 = (cnt[1] + 1) / 2;
	}
	else
	{
		cnt[0] = cnt[0] - cnt[2];
		sub1 = cnt[2];
		sub1 += (cnt[0] + 1) / 2;
		cnt[1] -= (cnt[0] + 1) / 2;
		sub2 = (cnt[1] + 1) / 2;
	}

	cout << sub1 + sub2 << endl;
	return 0;
}