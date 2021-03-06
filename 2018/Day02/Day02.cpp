// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "../Helper/helper.h"

int part1(const std::string fileName) {
	std::ifstream infile(fileName);
	std::string line;
	int twos = 0;
	int threes = 0;
	std::map<char, int>::iterator it;
	while (std::getline(infile, line)) {
		bool two = true;
		bool three = true;
		std::map<char, int> map;
		for (unsigned int i = 0; i < line.length(); i++) {
			it = map.find(line[i]);
			if (it != map.end()) {
				it->second = it->second + 1;
			}
			else {
				map[line[i]] = 1;
			}
		}

		for (auto const& x : map) {
			if (two && x.second == 2) {
				twos++;
				two = false;
			}
			if (three && x.second == 3) {
				threes++;
				three = false;
			}
		}
	}
	return twos * threes;
}

std::string part2(const std::string fileName) {
	auto lines = helper::fileToVector<std::string>(fileName);

	for (const auto& l1 : lines) {
		for (const auto& l2 : lines) {
			std::string match = "";
			int mismatch = 0;
			for (unsigned int i = 0; i < l1.length(); i++) {
				if (l1[i] == l2[i]) {
					match += l1[i];
					continue;
				}
				if (mismatch++ > 1) {
					break;
				}
			}
			if (mismatch == 1)
				return match;
		}
	}
	return "no box found";
}

int main()
{
	std::cout << "Hello World!\n";
	std::cout << part1("input.txt") << std::endl;
	std::cout << part2("input.txt") << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
