#include <bits/stdc++.h>
using namespace std;

/*
Session Recap:
	* Why we need OOP
	* Classes, Object
	* Constructor
	* Encapsulation
	* Access Modifier
*/

class Test {
	int x;
public:
	Test() {
		x = 9;
	}
	int getX() {
		return x;
	}
	void setX(int y) {
		x = y;
	}
};

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Test t;
	cout << t.getX() << endl;
	t.setX(50);
	cout << t.getX() << endl;
	return 0;
}

