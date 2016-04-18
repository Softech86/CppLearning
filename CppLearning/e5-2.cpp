#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>

using namespace std;

inline char next(char c, int step) {
	assert(isalpha(c));
	char ch = isupper(c) ? 'A' : 'a';
	return (c - ch + step + 26) % 26 + ch;
}

string caesarCipher(const string &s, int step) {
	string out = "";
	for (int i = 0; i < s.length(); ++i)
		out += next(s[i], step);
	return out;
}

int main() {
	string code;
	int step;
	cin >> code >> step;
	cout << caesarCipher(code, step);

	//system("pause");
	return 0;
}