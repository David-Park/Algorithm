#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

class atom
{
public:
	int xi=0, yi=0;
	int d=0;
	bool operator<(const atom &bb) const { return d < bb.d; }
};

std::vector<atom> a;
std::vector<atom> b;
int main()
{
	int testcase = 3;
	a.assign(200000, atom{});
	b.assign(200000, atom{});
	while(testcase> 0)
	{
		int n = 0, q = 0;
		int ax = 0, ay = 0, bx = 0, by = 0;
		scanf("%d", &n);

		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			scanf("%d %d", &a[i].xi, &a[i].yi);
		
		b = a;
		scanf("%d %d %d %d %d", &ax, &ay, &bx, &by, &q);

		for (int i = 0; i < n; i++)
		{
			a[i].d = pow((ax - a[i].xi), 2) + pow((ay - a[i].yi), 2);
			b[i].d = pow((bx - a[i].xi), 2) + pow((by - a[i].yi), 2);
		}
		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());

		printf("Case %d:\n", 4 - testcase);

		for (int i = 0; i < q; i++)
		{
			int r1 = 0, r2 = 0, c_1 = 0, c_2 = 0;
			scanf("%d %d", &r1, &r2);
			
			r1 = pow(r1, 2);
			r2 = pow(r2, 2);

			std::vector<atom>::iterator d1 = std::upper_bound(a.begin(), a.end(), r1);
			std::vector<atom>::iterator d2 = std::upper_bound(b.begin(), b.end(), r2);

			c_1 = (d1 - a.begin());
			c_2 = (d2 - b.begin());
			printf("%d\n", n - (c_1 + c_2));
		}
		testcase--;
	}
	return 0;
}