#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void display(const vector<float> &num) {
	for (int i = 0; i < num.size(); ++i)
		cout << num[i] << " ";
	cout << endl;
}

int main() {
	vector<float> num;
	const int maxn = 25;
	srand(int(time(0)));
	
	for (int i = 0; i < maxn; ++i) {
		float t = rand() % 1000 / 100.0;
		num.push_back(t);
	}
	display(num);

	for (int i = 0; i < num.size(); ++i)
		num[i] *= num[i];

	display(num);

	//system("pause");
	return 0;
}
