#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	int N = 0, M = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	sort(arr, arr + N);
	int _min = arr[0], _max = arr[N - 1];
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		if (_min > tmp || tmp > _max)
		{
			printf("0\n");
			continue;
		}
		
		if (binary_search(arr,arr+N,tmp))
			printf("1\n");
		else
			printf("0\n");
	}
	
	return 0;
}