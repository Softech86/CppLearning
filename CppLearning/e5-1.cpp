#include <string>

struct Location {
	int x, y, z;
};
typedef Location Speed;



class Car {
private:
	class BrakingSystem;
	//TODO:
public:
	int sizeX, sizeY, sizeZ;
	std::string color;
	int weight;

	Location loc;
	Speed spd;
	//TODO:
};

class Car::BrakingSystem {
public:
	void slowDown(int delta);
	void stop(int time);
	//TODO:
private:
	int leftTime;
	//TODO:
};