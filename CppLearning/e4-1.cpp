#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef struct {
	string word;
	int time;
} Pair;

bool compare(Pair a, Pair b) {
	return (a.time > b.time) || (a.time == b.time && a.word < b.word);
}

int main() {
	ifstream fin;
	bool lastConn = false;
	string word = "";
	char ch = ' ';

	map<string, int> tot;
	map<string, int>::iterator iter;

	//tot::iterator totIter;
	
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
			iter = tot.find(word);
			if (iter == tot.end())
				tot.insert(pair<string, int>(word, 1));
			else
				++iter->second;
			word = "";
			//system("pause");
		}
	}
	fin.close();
	
	vector<Pair> vTot;

	ofstream fout;
	fout.open("lexicographic.txt");
	for (map<string, int>::iterator iter = tot.begin(); iter != tot.end(); ++iter) {
		//cout << iter->first << " " << iter->second << endl;
		fout << iter->first << endl;
		Pair tot;
		tot.word = iter->first;
		tot.time = iter->second;
		vTot.push_back(tot);
	}
	fout.close();
	
	sort(vTot.begin(), vTot.end(), compare);

	fout.open("frequency.txt");
	for (vector<Pair>::iterator iter = vTot.begin(); iter != vTot.end(); ++iter)
		fout << iter->word << " " << iter->time << endl;
	fout.close();

	//system("pause");
	return 0;
}