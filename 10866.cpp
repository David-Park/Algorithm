#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	deque<int> deq;
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		int x;
		cin >> str;
		if (str == "push_front")
		{
			cin >> x;
			deq.push_front(x);
		}
		else if (str == "push_back")
		{
			cin >> x;
			deq.push_back(x);
		}
		else if (str == "pop_front")
		{
			if (deq.empty())
				cout << "-1\n";
			else
			{
				cout << deq.front() << '\n';
				deq.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (deq.empty())
				cout << "-1\n";
			else
			{
				cout << deq.back() << '\n';
				deq.pop_back();
			}
		}
		else if (str == "size")
		{
			cout << deq.size() << '\n';
		}
		else if (str == "empty")
		{
			if (deq.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front")
		{
			if (deq.empty())
				cout << "-1\n";
			else
			{
				cout << deq.front() << '\n';
			}
		}
		else if (str == "back")
		{
			if (deq.empty())
				cout << "-1\n";
			else
			{
				cout << deq.back() << '\n';
			}
		}
	}
	return 0;
}
/*
struct Node
{
	int value;
	Node *prev;
	Node *next;
	Node() { prev = NULL; next = NULL; };
	Node(int x) { this->value = x; Node(); };
};
class Dequeue
{
private:
	Node *data;
	Node *_front;
	Node *_back;
	int _size;
public:
	Dequeue();
	void push_front(int x);
	void push_back(int x);
	void pop_front();
	void pop_back();
	int size();
	bool empty();
	int front();
	int back();
};
int main()
{
	iostream::ios_base::sync_with_stdio(false);
	Dequeue deq;
	int N = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		string com;
		int x;
		cin >> com;
		if (com == "push_back" || com == "push_front")
		{
			cin >> x;
			if (com == "push_front")
				deq.push_front(x);
			else
				deq.push_back(x);
		}
		else if (com == "front")
			cout << deq.front() << "\n";
		else if (com == "back")
			cout << deq.back() << "\n";
		else if (com == "pop_front")
			deq.pop_front();
		else if (com == "pop_back")
			deq.pop_back();
		else if (com == "size")
			cout << deq.size() << "\n";
		else if (com == "empty")
			cout << deq.empty() << "\n";
	}
	return 0;
}

Dequeue::Dequeue() {
	this->data = new Node();
	this->_front = this->data;
	this->_back = this->data;
	this->_size = 0;
}
void Dequeue::push_front(int x) {
	this->_front->prev = new Node(x);
	this->_front->prev->next = new Node();
	this->_front->prev->next = this->_front;
	this->_front = this->_front->prev;
	this->_size++;
}
void Dequeue::push_back(int x) {
	this->_back->next = new Node(x);
	this->_back->next->prev = new Node();
	this->_back->next->prev = this->_back;
	this->_back = this->_back->next;
	this->_size++;
}
void Dequeue::pop_front() {
	if (this->empty())
		printf("-1\n");
	else {
		printf("%d\n", this->_front->value);
		this->_front = this->_front->next;
		this->_front->prev->next = NULL;
		this->_size--;
	}
}
void Dequeue::pop_back() {
	if (this->empty())
		printf("-1\n");
	else {
		printf("%d\n", this->_back->value);
		this->_back = this->_back->prev;
		this->_back->next->prev = NULL;
		this->_size--;
	}
}
int Dequeue::size() {
	return this->_size;
}
bool Dequeue::empty() {
	return this->size() ? false : true;
}
int Dequeue::front() {
	if (this->empty())
		return -1;
	else
		return this->_front->value;
}
int Dequeue::back() {
	if (this->empty())
		return -1;
	else
		return this->_back->value;
}
*/