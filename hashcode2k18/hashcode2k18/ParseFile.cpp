#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

class ParseFile {
public:
	std::ifstream infile;
	
	ParseFile(std::string filename) {
		infile = std::ifstream(filename);
	}

	void readFile() {
		std::string line;
		std::getline(infile, line);
		auto firstline = split(line, ' ');
		for (int i = 0; i < firstline.size(); i++) {
			switch (i) {
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			}
		}
		while (std::getline(infile, line))
		{
			auto splitline = split(line, ' ');
			for (int i = 0; i < splitline.size(); i++) {
				switch (i) {
				case 0:
					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				}
			}
		}
	}
private:
	template<typename Out>
	void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

		std::vector<std::string> split(const std::string &s, char delim) {
			std::vector<std::string> elems;
			split(s, delim, std::back_inserter(elems));
			return elems;
		}
};

