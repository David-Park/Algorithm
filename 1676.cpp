#include <iostream>
using namespace std;

int main()
{
	int N = 0, ans = 0;
	scanf("%d", &N);

	for (int i = 5; i < N; i *= 5)
		ans += N / i;

	printf("%d\n", ans);
	return 0;
}