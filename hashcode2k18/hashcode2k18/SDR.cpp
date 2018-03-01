#include <iostream>
#include <vector>
#include <memory>

class SDR {
public:
	int row;
	int col;
	int fleet;
	int rides;
	int bonus;
	int step;
	std::vector<std::shared_ptr<ride>> rides;
	std::vector<std::shared_ptr<car>> cars;
};

class ride {
public:
	vector2 start;
	vector2 finish;
	int earliest;
	int latest;
};

class vector2 {
public:
	int x;
	int y;
};

class car {
public:
	vector2 pos;
	std::shared_ptr<ride> currentRide;
};