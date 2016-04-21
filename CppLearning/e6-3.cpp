#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

enum Para { m, d, y };

class Date {
public:
	int month, day, year;
	Date(int m, int d, int y) {
		month = (m < 1 || m > 12) ? 1 : m;
		day = d;
		year = y; 
	}

	void set(int m, int d, int y);
	int get(Para p);
	void displayDate();
};

inline void Date::set(int m, int d, int y) {
	month = (m < 1 || m > 12) ? 1 : m;
	day = d;
	year = y;
}

inline void Date::displayDate() {
	printf("%d/%d/%d\n", month, day, year);
}

inline int Date::get(Para p) {
	return p == m ? month : p == d ? day : year;
}

int main() {
	Date date(11, 12, 1997);
	cout << date.get(m) << endl;
	cout << date.get(d) << endl;
	cout << date.get(y) << endl;

	date.set(13, 31, 2016);
	date.displayDate();

	//system("pause");
	return 0;
}