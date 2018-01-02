#include <iostream>
using namespace std;

int main()
{
	int N = 0, ans = 1;
	scanf("%d", &N);
	for (int i = 2; i <= N; i++)
		ans *= i;
	printf("%d\n", ans);
	return 0;
}