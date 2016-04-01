#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v = { 7, 6, 5, 4, 3 };
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << *(&v[0] + i) << endl;

	cout << *v.begin();

	system("pause");
	return 0;
}