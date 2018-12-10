#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "helper.h"

template<typename T>
std::vector<T> helper::fileToVector(const std::string fileName) {
	std::ifstream infile(fileName);
	std::string line;
	std::vector<T> list;

	while (std::getline(infile, line)) {
		list.push_back(line);
	}
	return list;
}

template std::vector<std::string> helper::fileToVector(const std::string filename);