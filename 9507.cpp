#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

long long d[67] = {1,1,2,4,};

int main()
{
	int t = 0;
	cin >> t;

	for (int i = 4; i <= 67; i++)
		d[i] = d[i - 1] + d[i - 2] + d[i - 3] + d[i - 4];

	for (int i = 0; i < t; i++)
	{
		int n = 0;
		cin >> n;

		cout << d[n] << endl;
	}
	return 0;
}