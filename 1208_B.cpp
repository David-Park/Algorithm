#include <cstdio>
#include <malloc.h>

int cnt;
int height[101];

void init() {
	cnt = 0;
	for (int i = 1; i < 101; i++) {
		height[i] = 0;
	}
}

int solution() {
	int ret = 0;
	int up = 100;
	int down = 1;
	
	//find non-zero
	while (!height[up]) {
		up--;
	}
	while (!height[down]) {
		down++;
	}

	while (cnt > 0 && up - down > 1) {	
		if (height[up] >= height[down]) {
			if (cnt >= height[down]) {
				cnt -= height[down];
				height[up] -= height[down];
				height[up - 1] += height[down];
				height[down + 1] += height[down];
				height[down] = 0;
				down++;
			}
			else {
				height[down] -= cnt;
				height[up] -= cnt;
				height[down + 1] += cnt;
				height[up - 1] += cnt;
				cnt = 0;
			}
		}
		else {
			if (cnt >= height[up]) {
				cnt -= height[up];
				height[down] -= height[up];
				height[down + 1] += height[up];
				height[up - 1] += height[up];
				height[up] = 0;
				up--;
			}
			else {
				height[up] -= cnt;
				height[down] -= cnt;
				height[up - 1] += cnt;
				height[down + 1] += cnt;
				cnt = 0;
			}
		}
	}

	ret = up - down;
	return ret;
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int temp = 0;
		int result = 0;
				
		init();
		scanf("%d", &cnt);
		for (int i = 0; i < 100; i++) {
			scanf("%d", &temp);
			height[temp]++;
		}
		result = solution();

		printf("#%d %d\n", tc, result);
	}
	return 0;
}