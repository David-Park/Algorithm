#include <iostream>
#include <string>
using namespace std;

/*
- ���ϸ��� "PreTest.Ȯ����"�� �����ϸ�, �ϳ��� ���Ϸθ� �����ϼ���.

* �б� ���� �ڵ尡 ���� �ڵ� �Դϴ�. �б� ���� �ڵ�� �ۼ��� �ּ���.
** �ð� ���⵵�� �޸� �̽�, ������ ���ɿ� ������ �μ���.
*** �䱸 ������ ��ȣ�ϴٸ�, �� �κ��� �������Ͽ� �����ϰ� �����Ͻÿ�.

����) �Է¹��� ���ڸ� �ѱ� �������� ��ȯ�Ͽ� Standard out���� ����ϴ� ���α׷��� ������� �մϴ�.
PreTest.java���, �Ʒ��� ���� �����ϵ��� �����Ͻÿ�. (�Է°��� 1 ~ 99999 �� ������ ����.)

~>java PreTest 37
���ĥ

~>java PreTest 2011
��õ����

~>java PreTest 90000
����
*/

void numToString(const char* num)
{
	int len = strlen(num);
	int cnt = len - 1;
	char digit_Kor[10][3] = { "", "��", "��", "��", "��", "��", "��", "ĥ", "��", "��"};
	char cipher_Kor[5][3] = { "", "��", "��", "õ", "��" };
	string ret = "";
	for (int i = 0; i < len; i++)
	{
		if (num[i] == '0')
		{
			cnt--;
			continue;
		}
		else if (num[i] == '1')
		{
			if (cnt > 0)
				ret += cipher_Kor[cnt];
			else
				ret += digit_Kor[num[i] - '0'];
		}
		else
		{
			ret += digit_Kor[num[i] - '0'];
			ret += cipher_Kor[cnt];
		}
		cnt--;
	}
	cout << ret << endl;
}

int main(char *argv[], int argc)
{
	for (int i = 1; i <= 99999; i++)
	{
		string buf = to_string(i);
		cout << i << " ";
		numToString(buf.c_str());
	}
	return 0;
}