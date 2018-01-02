#include <cstdio>

int mat[100][100];

int solution() {
	int ret = 0;
	int sum = 0;
	for (int i = 0; i < 100; i++) {//cross sum
		sum += mat[i][99 - i];
		ret += mat[i][i];
	}
	ret = ret < sum ? sum : ret;

	for (int i = 0; i < 100; i++) {
		sum = 0;
		for (int j = 0; j < 100; j++) {
			sum += mat[i][j];
		}
		ret = ret < sum ? sum : ret;
	}

	for (int i = 0; i < 100; i++) {
		sum = 0;
		for (int j = 0; j < 100; j++) {
			sum += mat[j][i];
		}
		ret = ret < sum ? sum : ret;
	}
	return ret;
}

int main() {
	for (int z = 1; z <= 10; z++) {
		int tc = 0;
		int result = 0;
		scanf("%d", &tc);

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%d", &mat[i][j]);
			}
		}

		result = solution();

		printf("#%d %d\n", tc, result);
	}
	return 0;
}