#include <iostream>
#include <vector>

using namespace std;

void printa(int i) {
	cout << i << "a\n";
}
void printb(int i) {
	cout << i << "b\n";
}
void printc(int i) {
	cout << i << "c\n";
}
void printd(int i) {
	cout << i << "d\n";
}
void printe(int i) {
	cout << i << "e\n";
}

//void(*pFunc)(int);
typedef void(*pInt)(int);

int main() {
	enum alpha {
		a, b, c, d, e
	};
	void(*funcs[])(int) = {
		printa, printb, printc, printd, printe
	};
	//vector<pInt> vFuncs(funcs[0], funcs[4]);
	vector<pInt> vFuncs;
	for (int i = 0; i < 5; ++i)
		vFuncs.push_back(funcs[i]);
	alpha ch = d;
	cout << ch << endl;

	for (int i = a; i <= e; ++i)
		funcs[i](i + 10);
	
	for (int i = a; i <= e; ++i)
		vFuncs[i](i + 10);

	system("pause");
	return 0;
}