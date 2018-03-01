#include "stdafx.h"
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <memory>
#include "SDR.hpp"

using namespace std;

class ParseFile {
public:
	ifstream infile;
	shared_ptr<SDR> _sdr;
	
	ParseFile(std::string filename, shared_ptr<SDR> sdr) {
		infile = std::ifstream(filename);
		_sdr = sdr;
	}

	void readFile() {
		string line;
		stringstream ss;
		getline(infile, line);
		_sdr->setValues(line);
		_sdr->cars.insert(_sdr->cars.begin(), _sdr->fleet, make_shared<Car>());
		int i = 0;
		while (std::getline(infile, line))
		{
			ss.str(line);
			_sdr->ridesList.push_back(make_shared<Ride>(line));
		}
	}
private:
	template<typename Out>
	void split(const std::string &s, char delim, Out result) {
	stringstream ss(s);
	string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}
};

