#include <iostream>
#include <string>

using namespace std;

void func1(string* s) {
	s->replace(20, 5, "out");
}

void func2(string &s) {
	s.replace(20, 5, "out");
}

int main() {
	string s1 = "HelloWorld from the other side.", s2;
	s2 = s1;
	cout << s1 << endl << s2 << endl;

	func1(&s1);

	cout << s1 << endl;

	func2(s2);

	cout << s2 << endl;

	system("pause");
}