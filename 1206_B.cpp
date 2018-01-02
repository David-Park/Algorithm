#include <cstdio>
#include <malloc.h>

/*
Cannot Use STL
*/
int max(int a, int b) {
	return a < b ? b : a;
}

int solution(int size, int* arry) {
	int ret = 0;
	for (int i = 2; i < size - 2; i++) {
		if (arry[i - 2] < arry[i] && arry[i - 1] < arry[i] && arry[i + 1] < arry[i] && arry[i + 2] < arry[i]) {
			ret += arry[i] - max(max(arry[i - 2], arry[i - 1]), max(arry[i + 1], arry[i + 2]));
		}
	}
	return ret;
}

int main() {
	for (int z = 1; z <= 10; z++) {
		int *arr;
		int size = 0;
		int result = 0;
		scanf("%d", &size);

		arr = (int *)malloc(sizeof(int) * size);

		for (int i = 0; i < size; i++) {
			scanf("%d", &arr[i]);
		}

		result = solution(size, arr);

		printf("#%d %d\n", z,result);
	}
	return 0;
}