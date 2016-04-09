#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

inline bool isOdd(int x) {
	return x % 2;
}

inline bool isEven(int x) {
	return !(x % 2);
}

template <typename elemType>
vector<elemType> filter(const vector<elemType> &data, bool (*judge)(elemType)) {
	vector<elemType> res;
	vector<elemType>::const_iterator iter = data.begin();
	while ((iter = find_if(iter, data.end(), judge)) != data.end()) {
		res.push_back(*iter);
		++iter;
	}
	return res;
}

int main() {
	ofstream oddFOut, evenFOut;
	oddFOut.open("odd.txt");
	evenFOut.open("even.txt");
	istream_iterator<int> is(cin), eof;
	ostream_iterator<int> osOdd(oddFOut, " "), osEven(evenFOut, "\n");
	vector<int> data;
	copy(is, eof, back_inserter(data));
	vector<int> f1 = filter(data, isOdd), f2 = filter(data, isEven);
	copy(f1.begin(), f1.end(), osOdd);
	copy(f2.begin(), f2.end(), osEven);
	//system("pause");
	return 0;
}