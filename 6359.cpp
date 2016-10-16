#include <iostream>
#include <math.h>
using namespace std;

int d[101] = { 0, };
int d2[101] = { 0, };
int main()
{
	int t = 0;
	cin >> t;

	d[1] = 1;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
				d[i]+=2;
		}
		if ((int)sqrt(i) != 1 && i == pow((int)sqrt(i), 2))
			d[i]--;
	}

	d2[1] = 1;
	for (int i = 2; i <= 100; i++)
	{
		d2[i] += d2[i - 1] + (d[i] & 0x01);
	}
	for (int i = 0; i < t; i++)
	{
		int n = 0, ans = 0;
		cin >> n;

		

		cout << d2[n] << endl;
	}
}