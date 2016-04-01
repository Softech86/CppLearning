#include <iostream>
#include <list>
 
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	list<int> person;
	for (int i = 1; i <= n; ++i)
		person.push_back(i);

	while (person.size() > 1) {
		for (int i = 1; i < m; ++i) {
			person.push_back(person.front());
			person.pop_front();
		}
		//cout << person.front() << " out" << endl;
		person.pop_front();
	}

	cout << person.front() << endl;
	//system("pause");
	return 0;
}