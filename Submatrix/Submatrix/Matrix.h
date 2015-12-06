// Stephen Belden
// Meghan Haukaas
// Chris Ruiz?

// 2015-Nov-19

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class Matrix {
public:
	Matrix();
	Matrix(string filename);
	Matrix(vector<vector<int>> input);
	void randomGenerate(int n);
	void silentRandomGenerate(int n);
	void printMatrix() const;
	void printAnswer() const;
	int findLargestSubmatrix() const;

private:
	vector<vector<int>> data;
	mutable int LSO = -1; // Largest Submatrix of Ones
};