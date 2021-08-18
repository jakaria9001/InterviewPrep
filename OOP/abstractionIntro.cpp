#include <bits/stdc++.h>
using namespace std;

/*class A {
	int x;
	string y;
public:
	A() {
		x = 500;
		y = "Hussain";
	}
	int getX() {
		return x;
	}
	string getY() {
		return y;
	}
	virtual void reduceX() {
		cout << "X reduced" << endl;

	}

	void print() {
		cout << x << " " << y << endl;
	}

};*/
class A
{
public:
	A(int a)
	{
		cout << " " << a;
	}
};

class B: public A
{
public:
	B(int a, int b): A(a)
	{
		cout << " " << b;
	}
};

class C: public B
{
public:
	C(int a, int b, int c): B(a, b)
	{
		cout << " " << c;
	}
};
class Baseclass1
{
public:
	Baseclass1()
	{
		cout << "Baseclass1's constructor called" << endl;
	}
	~Baseclass1()
	{
		cout << " Baseclass1's destructor" << endl;
	}
};

class Baseclass2
{
public:
	Baseclass2()
	{
		cout << "Baseclass2's constructor called" << endl;
	}
	~Baseclass2()
	{
		cout << " Baseclass2's destructor" << endl;
	}
};

class Derived: public Baseclass1, public Baseclass2
{
public:
	Derived()
	{
		cout << "Derived's constructor called" << endl;
	}
	~Derived()
	{
		cout << " Derived's destructor" << endl;
	}
};
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// Derived d;

	C c(10, 20, 30);
	return 0;
}

