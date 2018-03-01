#include "Header.h"
#include <sstream>
#include <vector>
using namespace std;

#ifndef _SDR_
#define _SDR_

class Vector2 {
public:
	int x;
	int y;
};
class Ride {
public:
	int _id;
	Vector2 start;
	Vector2 finish;
	int earliest;
	int latest;

	Ride(int id, string line) {
		stringstream ss(line);
		_id = id;
		ss >> start.y >> start.x >> finish.y >> finish.x >> earliest >> latest;
	}
};

class Car {
public:
	std::vector<std::shared_ptr<Ride>> rides;
};

class SDR {
public:
	int row;
	int col;
	int fleet;
	int rides;
	int bonus;
	int step;
	std::vector<std::shared_ptr<Ride>> ridesList;
	std::vector<Car> cars;
	
	void setValues(std::string line) {
		stringstream ss(line);
		ss >> row >> col >> fleet >> rides >> bonus >> step;
	}
};

#endif // !1