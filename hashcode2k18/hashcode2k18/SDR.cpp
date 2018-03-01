#include <iostream>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

class SDR {
public:
	int row;
	int col;
	int fleet;
	int rides;
	int bonus;
	int step;
	std::vector<std::shared_ptr<Ride>> ridesList;
	std::vector<std::shared_ptr<Car>> cars;
	
	void setValues(std::string line) {
		stringstream ss(line);
		ss >> row >> col >> fleet >> rides >> bonus >> step;
	}
};

class Ride {
public:
	Ride(int id,  string line) {
		stringstream ss(line);
		_id = id;
		ss >> start.y >> start.y >> finish.y >> finish.x >> earliest >> latest;
	}
	int _id;
	Vector2 start;
	Vector2 finish;
	int earliest;
	int latest;
};

class Vector2 {
public:
	int x;
	int y;
};

class Car {
public:
	std::vector<std::shared_ptr<Ride>> rides;
};