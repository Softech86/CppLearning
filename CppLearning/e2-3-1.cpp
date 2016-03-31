#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

int max(const vector<int> &data) {
	assert(data.size());
	int m = data[0];
	for (int i = 1; i < data.size(); ++i)
		if (data[i] > m)
			m = data[i];
	return m;
}

float max(const vector<float> &data) {
	assert(data.size());
	float m = data[0];
	for (int i = 1; i < data.size(); ++i)
		if (data[i] > m)
			m = data[i];
	return m;
}

string max(const vector<string> &data) {
	assert(data.size());
	string m = data[0];
	for (int i = 1; i < data.size(); ++i)
		if (data[i] > m)
			m = data[i];
	return m;
}

int max(const int *data, const int size) {
	assert(size > 0);
	int m = data[0];
	for (int i = 1; i < size; ++i)
		if (data[i] > m)
			m = data[i];
	return m;
}

float max(const float *data, const int size) {
	assert(size > 0);
	float m = data[0];
	for (int i = 1; i < size; ++i)
		if (data[i] > m)
			m = data[i];
	return m;
}

string max(const string *data, const int size) {
	assert(size > 0);
	string m = data[0];
	for (int i = 1; i < size; ++i)
		if (data[i] > m)
			m = data[i];
	return m;
}

void test() {
	int data4[7] = { 3, 2, 1, 4, 5, 6, 0 };
	float data5[6] = { 3.2, 2.1, 1.4, 4.5, 5.6, 6.0 };
	string data6[8] = { "a", "b", "c", "d", "aa", "g", "e", "ff" };
	int len4 = 7, len5 = 6, len6 = 8;
	vector<int> data1(data4, data4 + len4);
	vector<float> data2(data5, data5 + len5);
	vector<string> data3(data6, data6 + len6);
	
	cout << max(data1) << endl;
	cout << max(data2) << endl;
	cout << max(data3) << endl;
	cout << max(data4, len4) << endl;
	cout << max(data5, len5) << endl;
	cout << max(data6, len6) << endl;
}

int main() {
	test();
	//system("pause");
	return 0;
}