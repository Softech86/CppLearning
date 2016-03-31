#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>

using namespace std;

const int maxn = 1024;

vector<int> generate(const int &size) {
	//assert(size < 0);
	if (size <= 1 || size > maxn) {
		vector<int> res;
		if (size == 1) {
			res.push_back(0);
			res.push_back(1);
		}
		return res;
	}
	else {
		vector<int> &res = generate(size - 1);
		int len = res.size();
		res.push_back(res[len - 2] + res[len - 1]);
		return res;
	}
}

void print(const vector<int> &res) {
	if (res.size() == 0)
		cout << "EMPTY";
	else {
		for (int i = 1; i < res.size(); ++i)
			cout << res[i] << " ";
	}
	cout << endl;
}

int main() {
	int size = 0;
	cin >> size;

	double time0 = clock();

	vector<int> res = generate(size);
	print(res);
	
	cout << (clock() - time0) / CLOCKS_PER_SEC << endl;

	//system("pause");
	return 0;
}