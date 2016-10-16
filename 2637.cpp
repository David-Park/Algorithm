#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct item
{
	int itemnum;
	int partnum;
	int partcnt;
};
vector< vector<item> > toy(101, vector<item>());
int cntatomic[101] = { 0, };
int main()
{
	int toynum = 0, partnum = 0;
	int cntparts = 0;
	queue<int> part_parser;
	scanf("%d %d", &toynum, &partnum);

	for (int i = 1; i <= partnum; i++)
	{
		item temp;
		scanf("%d %d %d", &temp.itemnum, &temp.partnum, &temp.partcnt);
		toy[temp.itemnum].push_back(temp);
	}
	part_parser.push(toynum);
	while (!part_parser.empty())
	{
		int now_part = part_parser.front();
		part_parser.pop();

		for (vector<item>::iterator i = toy[now_part].begin(); i != toy[now_part].end(); i++)
		{
			if (cntatomic[now_part] == 0)
			{
				cntatomic[i->partnum] += i->partcnt;
			}
			else
			{
				cntatomic[i->partnum] += i->partcnt*cntatomic[now_part];
			}

			if (!toy[i->partnum].empty())
				part_parser.push(i->partnum);
		}
		cntatomic[now_part] = 0;
	}

	for (int i = 1; i < toynum; i++)
	{
		if (toy[i].empty())
			printf("%d %d\n", i, cntatomic[i]);
	}
	return 0;
}