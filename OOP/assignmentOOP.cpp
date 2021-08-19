#include<iostream>
using namespace std;

class B1    {
public:
    B1()    {
        cout << "\n In class class B1 constructor";
    }
    virtual ~B1()  {
        cout << "\n In B1 destructor";
    }
};

class D: public B1    {
public:
    D() {
        cout << "\n In derived class D's constructor";
    }
    ~D()    {
        cout << "\n In derived class D's Destructor";
    }
};

int main()    {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    B1 *p = new D();
    cout << "OK";
    delete p;
    return 0;
}
