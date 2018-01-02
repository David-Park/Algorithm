#include <iostream>
using namespace std;

class A {
public:
	virtual void name()
	{
		cout << "I'm A" << endl;
	}
	void hold()
	{
		cout << "I''ve got you!" << endl;
	}
};

class B :public A{
public:
	virtual void name() {
		cout << "I'm B" << endl;
	}
	void hold() {
		cout << "Please let me go!" << endl;
	}
};

class C :public B {
public:
	virtual void name() {
		cout << "I'm C" << endl;
	}
	void hold() {
		cout << "Sucseeding you father!" << endl;
	}
};

int main()
{
	A *a = new C;
	a->name();
	a->hold();

	B b1;
	a = &b1;
	a->name();
	a->hold();
	B *b = (B*)a;
	b->name();
	b->hold();
	return 0;
}