#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*template <typename elemType>
void swap(elemType &a, elemType &b) {
	elemType t = a;
	a = b; 
	b = t;
}*/

template <typename elemType>
void selectionSort(vector<elemType> &data) {
	int len = data.size();
	for (int i = 0; i < len - 1; ++i)
		for (int j = i + 1; j < len; ++j)
			if (data[i] > data[j])
				swap(data[i], data[j]);
}

template <typename elemType>
void bubbleSort(vector<elemType> &data) {
	int len = data.size();
	for (bool inorder = false; inorder = !inorder;) {
		for (int i = 0; i < len - 1; ++i)
			if (data[i] > data[i + 1]) {
				swap(data[i], data[i + 1]);
				inorder = false;
			}
	}
}

template <typename elemType>
void quickSort(vector<elemType> &data, int l, int r) {
	int i = l, j = r;
	elemType x = data[(l + r) / 2];
	do {
		while (data[i] < x)
			++i;
		while (data[j] > x)
			--j;
		if (i <= j) {
			swap(data[i], data[j]);
			++i;
			--j;
		}
	} while (i <= j);
	if (l < j)
		quickSort(data, l, j);
	if (i < r)
		quickSort(data, i, r);
}

template <typename elemType>
void sort(vector<elemType> &data) {
	quickSort(data, 0, data.size() - 1);
}

template <typename elemType>
void print(vector<elemType> &data) {
	for (int i = 0; i < data.size(); ++i)
		cout << data[i] << ' ';
	cout << endl;
}

int main() {
	int data4[7] = { 3, 2, 1, 4, 5, 6, 0 };
	float data5[6] = { 3.2, 2.1, 1.4, 4.5, 5.6, 6.0 };
	string data6[8] = { "e", "a", "b", "c", "d", "aa", "g", "ff" };
	int len4 = 7, len5 = 6, len6 = 8;
	vector<int> data1(data4, data4 + len4);
	vector<float> data2(data5, data5 + len5);
	vector<string> data3(data6, data6 + len6);

	sort(data1);
	print(data1);
	sort(data2);
	print(data2);
	sort(data3);
	print(data3);

	//system("pause");
	return 0;
}