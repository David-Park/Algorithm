#include <iostream>
#define q_size 11111
int main()
{
	int n = 0, a = 0, f_idx = 0, b_idx = 0;
	int p[q_size];
	char op[6];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", op);

		if (op[1] == 'u')
		{//push
			scanf("%d", &a);
			p[b_idx%q_size] = a;
			b_idx++;
		}
		else if (op[1] == 'o')
		{//pop
			if (f_idx != b_idx)
			{
				printf("%d\n", p[f_idx%q_size]);
				f_idx++;
			}
			else
				printf("-1\n");
		}
		else if (op[1] == 'i')
		{//size
			printf("%d\n", (q_size + b_idx - f_idx) % q_size);
		}
		else if (op[1] == 'm')
		{//empty
			if (f_idx == b_idx)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (op[1] == 'r')
		{//front
			if (f_idx != b_idx)
				printf("%d\n", p[f_idx]);
			else
				printf("-1\n");
		}
		else if (op[1] == 'a')
		{//back
			if (f_idx != b_idx)
				printf("%d\n", p[(q_size + b_idx - 1)%q_size]);
			else
				printf("-1\n");
		}
	}
	return 0;
}