#pragma once
#include <sstream>

void calc_max_width(int rows, int columns, int highest_val) {
	// get last value on array
	return cast_int_to_string(rows * columns * highest_val).length();
};

std::string cast_int_to_string(int data) {
	stringstream ss;
	string s;
	ss << data;
	ss >> s;
	return s;
};