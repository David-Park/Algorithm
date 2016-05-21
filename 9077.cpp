#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

struct addr
{
	int x;
	int y;
};

addr mine_addr[100000];
list<addr> mine[100000];
int n = 0, t=0;
int x=0, y=0;

void search(list<addr> *m,int index, int size)
{
	list<addr> quad[4];//0:x-10 y-10 1: x-10 y+10 2: x+10 y-10 3: x+10 y+10
	
	for (int i = 0; i < size; i++)
	{
		if (i == index)
			continue;

		if(mine_addr[i].x <mine_addr[index].x-10 || mine_addr[i].x > mine_addr[index].x+10)
			continue;
		else if (mine_addr[i].x >= mine_addr[index].x - 10 && mine_addr[i].x <= mine_addr[index].x)
		{
			if (mine_addr[i].y <mine_addr[index].y - 10 || mine_addr[i].y > mine_addr[index].y + 10)
				continue;
			else if (mine_addr[i].y >= mine_addr[index].y - 10 && mine_addr[i].y <= mine_addr[index].y)
			{//quad[0]
				quad[0].push_back(mine_addr[i]);
			}
			else
			{//quad[1]
				quad[1].push_back(mine_addr[i]);
			}
		}
		else
		{
			if (mine_addr[i].y <mine_addr[index].y - 10 || mine_addr[i].y > mine_addr[index].y + 10)
				continue;
			if (mine_addr[i].y >= mine_addr[index].y - 10 && mine_addr[i].y <= mine_addr[index].y)
			{//quad[2]
				quad[2].push_back(mine_addr[i]);
			}
			else
			{//quad[3]
				quad[3].push_back(mine_addr[i]);
			}
		}
	}

	if (quad[0].size() >= quad[1].size() && quad[0].size() >= quad[2].size() && quad[0].size() >= quad[3].size())
		m[index] = quad[0];
	else if (quad[1].size() >= quad[0].size() && quad[1].size() >= quad[2].size() && quad[1].size() >= quad[3].size())
		m[index] = quad[1];
	else if (quad[2].size() >= quad[1].size() && quad[2].size() >= quad[0].size() && quad[2].size() >= quad[3].size())
		m[index] = quad[2];
	else if(quad[3].size() >= quad[1].size() && quad[3].size() >= quad[2].size() && quad[3].size() >= quad[0].size())
		m[index] = quad[3];

	m[index].push_back(mine_addr[index]);
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		int max = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &mine_addr[i].x, &mine_addr[i].y);
		}
		search(mine, 0, n);
		max = mine[0].size();

		for (int i = 1; i < n; i++)
		{
			search(mine,i, n);
			if (mine[i].size() > max)
				max = mine[i].size();
		}
		printf("%d\n", max);
	}
	return 0;
}