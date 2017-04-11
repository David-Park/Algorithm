#include <iostream>
#include <string>
using namespace std;

void str_invert(string &s)
{
	for (int i = 0; i < s.length(); i++)
		s[i] == '0' ? s[i] = '1' : s[i] = '0';
}
int main()
{
	string str1, str2;
	int N = 0;

	cin >> N;
	cin >> str1 >> str2;

	if (N % 2 == 1)
		str_invert(str1);

	if (str1.compare(str2) == 0)
		cout << "Deletion succeeded" << endl;
	else
		cout << "Deletion failed" << endl;

	return 0;
}