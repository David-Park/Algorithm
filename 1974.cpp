#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
	int testcase = 0;

	scanf("%d", &testcase);
	for (int z = 0; z < testcase; z++)
	{
		int answer = 1;
		vector<vector<int> > sudoku(9,vector<int>(9,0));

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				scanf("%d", &sudoku[i][j]);

		for (int i = 0; i < 9; i++)
		{
			int t = 0;
			for (int j = 0; j < 9; j++)
				t += sudoku[i][j];

			if (t != 45)
			{
				answer = 0;
				goto print;
			}
		}

		for (int i = 0; i < 9; i++)
		{
			int t = 0;
			for (int j = 0; j < 9; j++)
				t += sudoku[j][i];

			if (t != 45)
			{
				answer = 0;
				goto print;
			}
		}

		for (int i = 0; i < 9; i++)
		{
			int t = 0;
			for (int j = 0; j < 9; j++)
				t += sudoku[i][j];

			if (t != 45)
			{
				answer = 0;
				goto print;
			}
		}

		for (int i = 0; i < 9; i += 3)
		{
			for (int j = 0; j < 9; j += 3)
			{
				int t = 0;
				for (int k = i; k < i + 3; k++)
					for (int l = j; l < j + 3; l++)
						t += sudoku[k][l];
				
				if (t != 45)
				{
					answer = 0;
					goto print;
				}
			}
		}

		print:
		printf("#%d %d\n", z + 1, answer);
	}
	return 0;
}