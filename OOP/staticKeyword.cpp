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

class Spaceship {
	string name;
	int noOfMissiles;
	int shieldStrength;
public:
	static int difficulty;

	Spaceship(string name) {
		this->name = name;
	}
	void fireMissile() {
		if (noOfMissiles > 0)
			-- noOfMissiles;
	}
	string getName() {
		return name;
	}
};
int Spaceship::difficulty = 101;

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Spaceship mySpaceship("IronManShip");

	cout << mySpaceship.getName() << endl;

	Spaceship carcruisher("SpiderShip");

	cout << carcruisher.getName() << endl;
	Spaceship::difficulty -= 1;
	cout << Spaceship::difficulty << endl;
	return 0;
}

