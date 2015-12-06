// Stephen Belden
// Meghan Haukaas

// 2015-Dec-06

#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Matrix.h"
#include <vector>
using std::vector;

int n;

void test(vector<vector<int>> input, int expected) {
	cout << "Case " << n << ":" << endl;
	Matrix matrix = Matrix(input);
	matrix.printMatrix();
	cout << endl << "Expected result: " << expected << endl;
	matrix.printAnswer();
	cout << endl << endl;
	n++;
}

void runAllTests() {
	n = 1;

	// A matrix of all 0's
	test(vector<vector<int>>{{0,0,0}, {0,0,0}, {0,0,0}}, 0);

	// A matrix of all 1's
	test(vector<vector<int>>{{1,1,1}, {1,1,1}, {1,1,1}}, 9);

	// A matrix with a single 1 as the greatest rectangle
	test(vector<vector<int>>{{0,0,0}, {0,1,0}, {0,0,0}}, 1);

	// A matrix with a greatest 1's square
	test(vector<vector<int>>{{0,1,1}, {0,1,1}, {0,0,0}}, 4);

	// A matrix with a greatest  1's rectangle
	test(vector<vector<int>>{{0,1,1}, {0,1,1}, {0,1,1}}, 6);

	// A matrix with a single colomn as its greatest submatrix
	test(vector<vector<int>>{{0,0,1}, {0,0,1}, {0,0,1}}, 3);

	// A matrix with a single row as its greatest submatrix
	test(vector<vector<int>>{{1,1,1}, {0,0,0}, {0,0,0}}, 3);

	// A matrix with a single greatest 1's rectangle and a distracting 1
	test(vector<vector<int>>{{1,1,0}, {1,1,0}, {0,0,1}}, 4);

	// A matrix with multiple, equal largest 1's rectangles
	test(vector<vector<int>>{{1,1,0,0}, {1,1,0,0}, {0,0,1,1}, {0,0,1,1}}, 4);

	// A matrix with a multiple equal, overlapping greatest 1's rectangles
	test(vector<vector<int>>{{1,1,0}, {1,1,1}, {1,1,1}}, 6);
}