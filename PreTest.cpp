#include <iostream>
#include <string>
using namespace std;

/*
- 파일명은 "PreTest.확장자"로 고정하며, 하나의 파일로만 구현하세요.

* 읽기 좋은 코드가 좋은 코드 입니다. 읽기 좋은 코드로 작성해 주세요.
** 시간 복잡도와 메모리 이슈, 최적의 성능에 중점을 두세요.
*** 요구 사항이 모호하다면, 그 부분을 재정의하여 서술하고 구현하시오.

문제) 입력받은 숫자를 한글 구음으로 변환하여 Standard out으로 출력하는 프로그램을 만들고자 합니다.
PreTest.java라면, 아래와 같이 동작하도록 구현하시오. (입력값은 1 ~ 99999 의 정수에 한함.)

~>java PreTest 37
삼십칠

~>java PreTest 2011
이천십일

~>java PreTest 90000
구만
*/

void numToString(const char* num)
{
	int len = strlen(num);
	int cnt = len - 1;
	char digit_Kor[10][3] = { "", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"};
	char cipher_Kor[5][3] = { "", "십", "백", "천", "만" };
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