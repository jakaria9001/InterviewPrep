#include <bits/stdc++.h>
using namespace std;


// private, public

class ArrayList {
//  private: // not accessible directly outside the class and also not inheritable
//   vector<int> arr;

protected: // will be able to access it directly in the derived classes through inheritances
// but stil can't access them outside the class via the object directly
// use case: to make data inheritable but still protecting from the outside world
	vector<int> arr;

public:
	// static, overloaded constructor
	ArrayList() {
		cout << "Constructor without param called\n";
		arr = {};
	}

	ArrayList(vector<int> input_arr) {
		cout << "Constructor with param called\n";
		// this->arr = arr;
		arr = input_arr;
	}

	vector<int> getArray() { return arr; }
	// telling the compiler to override it on the runtime depending on the type of
	// object virtual method is one which can be overriden on the run time
	// depending on the type of the object


	// when the program is run, the processor knows
	// that we need to check for the overriden method at runtime
	// tells the program that
	// if method has been overriden
	// at runtime determine which method to be called
	virtual void add(int x) {
		cout << "calling the normal add method\n";
		arr.push_back(x);
	}

	// this is an abstract method
	// pure virtual method
	// virtual int add(int x) = 0;

	int size() { return arr.size(); }

	void print() {
		for (int i = 0; i < arr.size(); ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

// private is never inherited in any of the modes

// in this public mode of inheritance (PUBLIC)
// public data of base -> public data of derived
// protected data of base -> protected data of derived

// protected mode of inheritance
// public data of base -> protected data of derived
// protected data of base -> protected data of derived

// we want to push only the non-negative integers in the arr list in the class
class NonNegativeArrayList : public ArrayList {

public:
	// colon is the initialiser list
	// we can specify the constructor to be called since we have more than one of them
	NonNegativeArrayList(vector<int> arr) {
		// parameterised constructor to be called for the base class
		cout << "Calling the non negative array list constructor\n";
		// validating the data
		// keep only the non-negative integers
		for (int i = 0; i < arr.size(); ++i) {
			add(arr[i]);  // automatically check if arr[i] is non-negative and insert
		}
	}
	// passed-by value
	// x will be local copy
	void add(int x);  // only the declaration or signature here
};

// definition outside class
// scope resolution operator
// in which class is my method coming
// tell it before I tell the method name
// returnType className::methodName(args)
void NonNegativeArrayList::add(int x) {
	// ignore the negative integers
	cout << "calling the non-negative add method\n";
	if (x >= 0) {
		// arr refers to the inherited attribute
		arr.push_back(x);
	}
}

// call by value -> copy created
// NonNegativeArrayList inherits from ArrayList
// so ArrayList constructor is called
// that is why it is also an object of the base class (analogy because base constructor is called)

void print(ArrayList arr) {
	cout << "Calling this independent print function" << endl;
	arr.print();
}

// call by value by default copy of object made
// call by reference object used at same memory location as the caller object

// this calls the add method of the ArrayList class
// even though we the pass the object of NonNegativeArrayList
// it should the detect the type of the object and call the appropriate method
void addOutside(ArrayList& arr, int x) {
	// we want the program when it is being run
	// to determine which object it is
	// because it be could be an object of ArrayList's dervied class
	// so we might want the overriden method to be called

	// we want the program to determine the object type and call the overrriden method
	// compiler will only look ArrayList methods as that is the input type
	// but we want it to look at the NonNegativeArrayList methods when program is being run
	cout << " --- Calling this independent add function" << endl;
	arr.add(x);
	arr.print();
}

/*
// function independent of a class
// that can take any type of bird as an input
void fly(Bird b) {
  if (b.name == "hen") {
    cout << "hen is flying" << endl;
  } else if (b.name == "eagle") {
    cout << "eagle is flying" << endl;
  }
}
*/

int main () {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ArrayList myArrayList;

	cout << myArrayList.size() << endl;

	myArrayList.add(10);

	myArrayList.print();

	cout << myArrayList.size() << endl;

	print(myArrayList);
	addOutside(myArrayList, -1);

	// if you already have a custom constructor
	// the default constructor without arguments is not auto created for you
	// NonNegativeArrayList myNonNegativeArrayList;


	vector<int> temp = { -1, 2, 10, -5};
	NonNegativeArrayList myNonNegativeArrayList(temp);

	myNonNegativeArrayList.print();

	// cout << myNonNegativeArrayList.size() << endl;

	// print(myNonNegativeArrayList);

	addOutside(myNonNegativeArrayList, -1);
	addOutside(myNonNegativeArrayList, 99);

	return 0;
}
