#include <iostream>
#include <vector>
using namespace std;

class stack_int
{
private:
	vector<int> arry;
	unsigned int indx;
public:
	stack_int()
	{
		this->arry.clear();
		this->indx = 0;
	}

	void push(int x)
	{
		this->arry.push_back(x);
		this->indx++;
	}
	int pop()
	{
		if (this->empty())
			return -1;
		else
		{
			int tmp = this->arry.at(this->indx - 1);
			this->arry.pop_back();
			this->indx--;
			return tmp;
		}
	}
	int size()
	{
		return this->indx;
	}
	int empty()
	{
		if (this->indx == 0)
			return 1;
		else
			return 0;
	}
	int top()
	{
		if (this->empty() != 1)
			return this->arry.at(this->indx - 1);
		else
			return -1;
	}
};

int main()
{
	int n = 0, a = 0;
	char op[6];

	stack_int st = stack_int();

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", op);
		if (op[0] == 't')
		{
			printf("%d\n", st.top());
		}
		else if (op[0] == 's')
		{
			printf("%d\n", st.size());
		}
		else if (op[1] == 'u')
		{
			scanf("%d", &a);
			st.push(a);
		}
		else if (op[1] == 'o')
		{
			printf("%d\n", st.pop());
		}
		else if (op[0] == 'e')
		{
			printf("%d\n", st.empty());
		}
	}
	return 0;
}