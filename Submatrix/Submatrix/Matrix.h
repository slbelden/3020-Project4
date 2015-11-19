// Stephen Belden
// Meghan Haukaas
// Chris Ruiz?

// 2015-Nov-19

#pragma once

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class Matrix {
public:
	Matrix();
	Matrix(string filename);
	void randomGenerate(int n);
	void print() const;
	int findLargestSubmatrix() const;

private:
	vector<vector<int>> data;
};