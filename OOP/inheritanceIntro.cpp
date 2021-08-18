#include <bits/stdc++.h>
using namespace std;

// class Bird {
// private:
// 	double height, weight;
// 	string color;
// public:
// 	void fly() {
// 		cout << "I am flying";
// 	}
// };


class SpaceShip {
	string callSign;
	int shieldStrength;
public:
	SpaceShip() {
		cout << "Spaceship constructor called." << endl;
		callSign = "Nameless Spaceship";
		shieldStrength = 100;
	}

	void print() {
		cout << "Name: " << callSign << endl;
		cout << "Strength: " << shieldStrength << endl;
	}

	int getShieldStrength() {
		return shieldStrength;
	}
	void reduceShieldStrength(int amount) {
		if (shieldStrength > 10) shieldStrength -= 10;
		else cout << "Strength already low" << endl;
	}
};

class FireFighter: public SpaceShip {
	int fireStrength;
public:
	FireFighter() {
		cout << "FireFighter constructor called." << endl;
		fireStrength = getShieldStrength() * 2;
		cout << fireStrength << endl;
	}
	void fireMissile() {
		cout << "Missile fired, Strength reduced by 10";
		fireStrength -= 10;
	}

};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// Bird* hen = new Bird();
	// hen->fly();
	// SpaceShip ship;
	// ship.print();

	FireFighter fire;
	fire.fireMissile();
	return 0;
}

