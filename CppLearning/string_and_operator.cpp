#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	ifstream fin;
	fin.open("data_string_and_operator.txt");
	string word;
	static int counter = 0;

	while (fin >> word) {
		for (int i = 0; i < word.length(); ++i)
			word[i] = tolower(word[i]);

		if (word == "that")
			++counter;
	}
	cout << counter << endl;

	fin.close();
	system("pause");
	return 0;
}