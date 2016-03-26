#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

const int maxn = 1024;

vector<int> generate(const int &size) {
	vector<int> res = { 0 };
	//assert(size < 0);
	if (size <= 0 || size > maxn)
		return res;
	for (int i = 0; i < size; ++i)
		res.push_back(res[i] + 3 * i + 1);
	return res;
}

void print(const vector<int> v, const string name) {
	cout << name << endl;
	if (v.size() == 1)
		cout << "EMPTY";
	for (int i = 1; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

int main() {
	int size = 0;
	string name = "";
	cin >> size >> name;
	vector<int> res = generate(size);
	print(res, name);
	//system("pause");
	return 0;
}