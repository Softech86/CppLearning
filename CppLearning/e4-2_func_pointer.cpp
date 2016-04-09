#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

typedef bool(*compareFunc)(const string&, const string&);

bool compare(const string &a, const string &b) {
	int aLen = a.length(), bLen = b.length();
	return (aLen < bLen) || (aLen == bLen && a < b);
}

template <typename elemType>
int find(const vector<elemType> &data, const elemType &elem) {
	//data cannot be set as const unless use const_iterator later
	for (vector<elemType>::const_iterator iter = data.begin(); iter != data.end(); ++iter) {
		if ((*iter) == elem)
			return iter - data.begin();
	}
	return -1;
}

template <typename elemType>
void sort(vector<elemType> &data, compareFunc cmp) {
	//just selection sort..shame on me..
	for (int i = 0; i < data.size() - 1; ++i) 
		for (int j = i + 1; j < data.size(); ++j)
			if (!cmp(data[i], data[j]))
				swap(data[i], data[j]);
}

int main() {
	ifstream fin;
	bool lastConn = false;
	string word = "";
	char ch = ' ';
	vector<string> tot;

	fin.open("article.txt");
	while (!fin.eof()) {
		ch = char(fin.get());
		if (isalpha(ch)) {
			word += tolower(ch);
			lastConn = false;
		}
		else {
			if (ch == '-' && !lastConn && word != "") {
				word += ch;
				lastConn = true;
				continue;
			}
			if (isblank(ch) && lastConn) {
				continue;
			}
			if (word == "")
				continue;
			//cout << word << endl;
			int p = find(tot, word);
			if (p == -1)
				tot.push_back(word);
			word = "";
			//system("pause");
		}
	}
	fin.close();
	//cout << tot.size() << " read" << endl;

	sort(tot, compare);
	//cout << "sorted" << endl;

	ofstream fout;
	fout.open("sorted.txt");
	for (vector<string>::iterator iter = tot.begin(); iter != tot.end(); ++iter) {
		//cout << (*iter) << endl;
		fout << (*iter) << endl;
	}
	fout.close();

	//system("pause");
	return 0;
}