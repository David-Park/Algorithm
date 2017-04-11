#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#define INF 1234567890
using namespace std;

vector<int> arr;

class comp
{
	bool rev;
public:
	comp(const bool& revparam=false)
	{
		rev = revparam;
	}
	bool operator() (const pair<int, int>&a, const pair<int, int>&b)const
	{
		if (rev)return(a.second < b.second);
		else return (a.second > b.second);
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q;

int main()
{
	int n = 0, l = 0;
	register int i;
	scanf("%d %d", &n, &l);
	arr.assign(n+1, INF);
	for (i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	
	for (i = 1; i <= l; i++)
	{
		q.push(make_pair(i, arr[i]));
		printf("%d ", q.top().second);
	} 

	for (i; i <= n; i++)
	{
		while (!q.empty() && q.top().first < i - l + 1)
			q.pop();

		q.push(make_pair(i, arr[i]));
		
		printf("%d ", q.top().second);
	}
	printf("\n");
	return 0;
}