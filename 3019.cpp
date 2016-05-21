#include <iostream>
#include <cstdio>
using namespace std;

int tetris[100] = { 0, };

int check_profit(int c, int p)
{
	int count = 0;
	//1~7
	//1:1,4 2:2 3:2,3 4:2,3 5:2,3 6:2,3 7:2,3
	switch (p)
	{
	case 1:
		for (int i = 0; i < c - 3; i++)
		{
			if (tetris[i] == tetris[i + 1] && tetris[i] == tetris[i + 2] && tetris[i] == tetris[i + 3])
			{
				count++;
			}
		}
		count += c;
		break;
	case 2:
		for (int i = 0; i < c - 1; i++)
		{
			if (tetris[i] == tetris[i + 1])
			{
				count++;
			}
		}
		break;
	case 3:
		for (int i = 0; i < c - 2; i++)
		{
			if (tetris[i] == tetris[i + 1] && tetris[i] == tetris[i + 2] - 1)
			{
				count++;
			}
			else if (tetris[i] == tetris[i + 1] + 1)
			{
				count++;
			}
		}
		if (tetris[c - 2] == tetris[c - 1] + 1)
		{
			count++;
		}
		break;
	case 4:
		for (int i = 0; i < c - 2; i++)
		{
			if (tetris[i] == tetris[i + 1] + 1 && tetris[i] == tetris[i + 2] + 1)
			{
				count++;
			}
			else if (tetris[i] == tetris[i + 1] - 1)
			{
				count++;
			}
		}
		if (tetris[c - 2] == tetris[c - 1] - 1)
		{
			count++;
		}
		break;
	case 5:
		for (int i = 0; i < c - 2; i++)
		{
			if (tetris[i] == tetris[i + 1] && tetris[i] == tetris[i + 2])
			{
				count++;
			}
			else
			{
				if (tetris[i] == tetris[i + 1] + 1)
				{
					count++;
					if (tetris[i] == tetris[i + 2])
					{
						count++;
					}
				}
				if (tetris[i] == tetris[i + 1] - 1)
				{
					count++;
				}
			}
		}
		if (tetris[c - 2] == tetris[c - 1] + 1)
			count++;
		else if (tetris[c - 2] == tetris[c - 1] - 1)
			count++;
		break;
	case 6:
		for (int i = 0; i < c - 2; i++)
		{
			if (tetris[i] == tetris[i + 1])
			{
				count++;
				if (tetris[i] == tetris[i + 2])
					count++;
			}
			else if (tetris[i] == tetris[i + 1] - 1 && tetris[i] == tetris[i + 2] -1)
			{
				count++;
			}
			else if (tetris[i] == tetris[i + 1] + 2)
				count++;
		}
		if (tetris[c - 2] == tetris[c - 1])
			count++;
		else if (tetris[c - 2] == tetris[c - 1] + 2)
			count++;
		break;
	case 7:
		for (int i = 0; i < c - 2; i++)
		{
			if (tetris[i] == tetris[i + 1])
			{
				count++;
				if (tetris[i] == tetris[i + 2])
					count++;
				else if (tetris[i] == tetris[i + 2] +1)
				{
					count++;
				}
			}
			else if (tetris[i] == tetris[i + 1] - 2)
				count++;
		}
		if (tetris[c - 2] == tetris[c - 1])
			count++;
		else if (tetris[c - 2] == tetris[c - 1] - 2)
			count++;
		break;
	default:
		break;
	}

	return count;
}

int main()
{
	int c = 0, p = 0;

	scanf("%d %d", &c, &p);

	for (int i = 0; i < c; i++)
	{
		scanf("%d", &tetris[i]);
	}

	printf("%d\n", check_profit(c, p));
	return 0;
}