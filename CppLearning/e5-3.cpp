#include <string>
#include <iostream>

using namespace std;

class Student {
private:
public:
	string firstName, lastName;
	int studentID;

	Student(string &fName, string &lName, int stuID);
	Student(char* fName, char* lName, int stuID) {
		string f = fName, l = lName;
		*this = Student(f, l, stuID);
	};
	void reset(string fName, string lName, int stuID);
	int showID();
	string showFullName();

	void status();
};

Student::Student(string &fName, string &lName, int stuID) {
	firstName = fName;
	lastName = lName;
	studentID = stuID;
}

void Student::reset(string fName, string lName, int stuID) {
	firstName = fName;
	lastName = lName;
	studentID = stuID;
}

inline int Student::showID() {
	return studentID;
}

inline string Student::showFullName() {
	return firstName + " " + lastName;
}

inline void Student::status() {
	cout << "----" << endl;
	cout << showID() << endl;
	cout << showFullName() << endl;
	cout << "----" << endl;
}

int main() {
	Student stu1("Jim", "Raid", 1552000);
	stu1.status();

	stu1.reset("Ë÷", "¿Æ", 1552600);
	stu1.status();

	//system("pause");
	return 0;
}