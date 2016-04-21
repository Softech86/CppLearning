#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct Point {
	int x, y;
	const bool operator < (const Point b) const {
		return (x < b.x) || ((x == b.x) && (y < b.y));
	}
};

class Rectangle {
public:
	Point location;
	int weight, height;

	Rectangle(int x, int y, int w, int h) {
		assert(w >= 0 && h >= 0);
		location.x = x;
		location.y = y;
		weight = w;
		height = h;
	}


	const bool operator < (Rectangle b) {
		//return weight * height < b.weight * b.height;
		return findArea() < b.findArea();
	}

	double findArea();
	double findPerimeter();
	void display();
};

inline double Rectangle::findArea() {
	printf("--Asked to find area of Rectangle( (%d, %d), %d, %d ).\n", location.x, location.y, weight, height);
	return weight * height;
}

inline double Rectangle::findPerimeter() {
	printf("--Asked to find preimeter of Rectangle( (%d, %d), %d, %d ).\n", location.x, location.y, weight, height);
	return (weight + height) << 1;
}

inline void Rectangle::display() {
	printf("--Asked to display of Rectangle( (%d, %d), %d, %d ).\n", location.x, location.y, weight, height);
	printf("Report parameters of the object:\n  Location: (%d, %d),\n  Weight: %d,\n  Height: %d.\n", location.x, location.y, weight, height);
}

int main() {
	Rectangle r1(1, 2, 6, 7);
	Rectangle r2(-1, -2, 3, 11);
	Rectangle r3(1, 2, 3, 2);
	r1.findArea();
	r2.findPerimeter();
	r3.display();
	cout << endl;

	vector<Rectangle> vr = { r3, r2, r1 };
	sort(vr.begin(), vr.end());
	for (vector<Rectangle>::iterator i = vr.begin(); i != vr.end(); ++i)
		i->display();

	//system("pause");
	return 0;
}