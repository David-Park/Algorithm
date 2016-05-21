#include <iostream>
#include <cstdio>

int main()
{
	int match = 0;
	int result = 0;
	scanf("%d", &match);

	if (match % 2 == 0)
	{
		for (int i = 2; i <= match / 3; i++)
		{
			for (int j = (match - i) / 2; j + i > match - j - i && j >= i; j--)
			{
				result++;
			}
		}
	}
	else
	{
		for (int i = 1; i <= match / 3; i++)
		{
			for (int j = (match - i) / 2; j + i > match - j - i && j >= i; j--)
			{
				result++;
			}
		}
	}

	printf("%d\n", result);
	return 0;
}