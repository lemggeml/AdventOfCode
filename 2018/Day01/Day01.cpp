// Day01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

std::vector<int> fileToVector(const std::string fileName) {
	std::ifstream infile(fileName);
	std::string line;
	std::vector<int> list;
	while (std::getline(infile, line)) {
		list.push_back(std::stoi(line));
	}
	return list;
}

int part1() {
	std::string line;
	std::vector<int> list = fileToVector("input.txt");
	auto sum = 0;
	for (auto& l : list) {
		sum += l;
	}
	return sum;
}

int part2() {
	std::set<int> seen;
	std::vector<int> list = fileToVector("input.txt");

	auto sum = 0;
	seen.insert(sum);
	while (true) {
		for (const int& i : list) {
			sum += i;
			if (seen.find(sum) != seen.end()) {
				return sum;
			}
			seen.insert(sum);
		}
	}
}

int main()
{
	std::cout << part1() << std::endl;
	std::cout << part2() << std::endl;
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
