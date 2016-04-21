#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const double PI = 3.1415927l;

struct Point {
	int x, y;
	const bool operator < (const Point b) const {
		return (x < b.x) || ((x == b.x) && (y < b.y));
	}
};

class Circle {
public:
	Point location;
	int radius;
	
	Circle(int x, int y, int r) {
		assert(r >= 0);
		location.x = x;
		location.y = y;
		radius = r;
	}

	const bool operator < (const Circle b) const {
		return radius < b.radius;
	}

	double findArea();
	double findPerimeter();
	void display();
  };

inline double Circle::findArea() {
	printf("--Asked to find area of Circle( (%d, %d), %d ).\n", location.x, location.y, radius);
	return PI * radius * radius;
}

inline double Circle::findPerimeter() {
	printf("--Asked to find preimeter of Circle( (%d, %d), %d ).\n", location.x, location.y, radius);
	return 2 * PI * radius;
}

inline void Circle::display() {
	printf("--Asked to display of Circle( (%d, %d), %d ).\n", location.x, location.y, radius);
	printf("Report parameters of the object:\n  Location: (%d, %d),\n  Radius: %d.\n", location.x, location.y, radius);
}

int main() {
	Circle c1(1, 2, 6);
	Circle c2(-1, -2, 3);
	Circle c3(1, 2, 13);
	c1.findArea();
	c2.findPerimeter();
	c3.display();
	cout << endl;

	vector<Circle> vc = { c3, c1, c2 };
	sort(vc.begin(), vc.end());
	for (vector<Circle>::iterator i = vc.begin(); i != vc.end(); ++i)
		i->display();

	//system("pause");
	return 0;
}