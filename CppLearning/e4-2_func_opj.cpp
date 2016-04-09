#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Cmp {
public:
	bool operator()(string &a, string &b) const;
};

inline bool Cmp::operator()(string &a, string &b) const {
	return (a.length() < b.length()) || (a.length() == b.length() && a < b);
}

template <typename elemType>
int find(vector<elemType> &data, const elemType &elem) {
	/*int l = 0, r = data.size() - 1;
	while (l != r) {
	if (elem <= data[(l + r) / 2])
	r = (l + r) / 2;
	else
	l = (l + r) / 2 + 1;
	}`
	if (data[l] != elem)
	return -1;
	return l;*/
	for (vector<elemType>::iterator iter = data.begin(); iter != data.end(); ++iter) {
		if ((*iter) == elem)
			return iter - data.begin();
	}
	return -1;
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

	Cmp cmp;
	sort(tot.begin(), tot.end(), cmp);

	ofstream fout;
	fout.open("sorted_.txt");
	for (vector<string>::iterator iter = tot.begin(); iter != tot.end(); ++iter) {
		//cout << (*iter) << endl;
		fout << (*iter) << endl;
	}
	fout.close();

	//system("pause");
	return 0;
}