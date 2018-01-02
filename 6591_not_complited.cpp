#include <iostream>
using namespace std;

int main()
{
	int n = 0, k = 0;
	while (1)
	{
		
		scanf("%d %d", &n, &k);
		if (n == 0 && k == 0)
			return 0;
		if (k > (n + 1) / 2)
			k = n - k;


	}
	return 0;
}