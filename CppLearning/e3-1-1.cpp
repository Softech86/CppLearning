#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>

using namespace std;

const int maxn = 1024;

void generate(const int &size, int* &resHead, int* &resTail) {
	//assert(size < 0);
	if (size <= 0 || size > maxn) {
		resHead = resTail = NULL;
		return;
	}
	resHead = new int[size + 1];
	(*resHead) = 0;
	resTail = ++resHead;
	(*resTail) = 1;
	for (int i = 1; i < size; ++i) {
		(*(resTail + 1)) = (*resTail) + (*(resTail - 1));
		++resTail;
	}
	return;
}

void print(int *vHead, int *vTail) {
	if (vHead == NULL)
		cout << "EMPTY";
	else {
		for (int *p = vHead; p <= vTail; ++p)
			cout << (*p) << " ";
	}
	cout << endl;
}

int main() {
	int size = 0;
	cin >> size;

	double time0 = clock();

	int *resHead, *resTail;
	generate(size, resHead, resTail);
	print(resHead, resTail);
	if (resHead)
		delete [] --resHead;

	cout << (clock() - time0) / CLOCKS_PER_SEC << endl;

	//system("pause");
	return 0;
}