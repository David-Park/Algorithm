#include <cstdio>

void swap(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

char* solve(char* str, int num)
{
	int len = 0, cnt = 0;
	int n[10] = { 0,0,0,0,0,0,0,0,0,0 };
	char best[7];
	for (int i = 0; i < 7; i++)
		if (str[i] < '0' || str[i] > '9')
			break;
		else
		{
			len++;
			n[str[i] - '0']++;
		}
	for (int i = 9; i >= 0; i--)
	{
		while (n[i]--)
			best[cnt++] = i +'0';
	}
	cnt = 0;

	for (int i = 0; i < len - 1; i++)
	{
		int tmp = i;
		for (int j = len - 1; j > i; j--)
			if (str[tmp] < str[j])
			{
				tmp = j;
			}
			else if (str[tmp] == str[j])
			{
				if (str[i] >= best[j])
					tmp = j;
			}
		if (str[i] < str[tmp])
		{
			swap(str[i], str[tmp]);
			cnt++;
		}

		if (cnt == num)
			break;
	}

	if (num > cnt)
	{
		num -= cnt;

		if (str[0] == str[1])
			return str;
		else if (num & 1 == 1)
			swap(str[len - 1], str[len - 2]);
	}

	return str;
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++)
	{
		char buf[7];
		char* answer;
		int num;
		scanf("%s %d", buf, &num);
		answer = solve(buf, num);
		printf("#%d %s\n", tc, answer);
	}
}