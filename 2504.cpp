#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	iostream::ios_base::sync_with_stdio(false);
	string str;
	vector<int> check(31, 0);
	vector<int> point(31, 0);
	cin >> str;

	for (int i = 0, layer = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[')
		{
			check[layer++] = str[i] == '(' ? ')' : ']';
		}
		if (str[i] == ')' || str[i] == ']')
		{
			layer--;
			if (layer < 0 || check[layer] != str[i])
			{
				point[0] = 0;
				break;
			}
			point[layer] += (str[i] == ')' ? 2 : 3) * (point[layer + 1] != 0 ? point[layer + 1] : 1);
			point[layer + 1] = 0;
		}
	}

	cout << point[0] << "\n";
	return 0;
}