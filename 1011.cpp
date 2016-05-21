#include <iostream>
#include <cstdio>
#include <vector>
 
int main()
{
	int t = 0;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int source = 0, dest = 0;
		unsigned int res = 1, d = 0, k = 1;
		scanf("%d %d", &source, &dest);
		d = dest - source;

		while (1)
		{
			if (d > 1 + res*(res + 1) / 2)
				res++;
			else
			{
				res--;
				break;
			}
		}

		for (int j = 1; j <= res; j++)
		{

		}
		printf("%d\n", res);
	}
	return 0;
}