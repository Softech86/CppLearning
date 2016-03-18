#include <iostream>
#include <string>

using namespace std;

typedef struct _Person {
	string firstName;
	string lastName;
	int age;

	_Person(string fName, string lName, int a) {
		firstName = fName;
		lastName = lName;
		age = a;
	}
	void print();
} Person;

void _Person::print() {
	cout << firstName << " " << lastName << " -- " << age << endl;
}

int main() {
	Person aPal("Tom", "Raid", 19);
	aPal.print();

	Person *bPal = new Person("J", "S", 0);
	bPal->print();

	bPal->firstName = "Jane";
	bPal->lastName = "Smith";
	bPal->age = 21;
	bPal->print();

	system("pause");
	return 0;
}