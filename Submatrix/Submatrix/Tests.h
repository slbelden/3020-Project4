// Stephen Belden
// Meghan Haukaas
// Chris Ruiz?

// 2015-Nov-19

#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Matrix.h"
#include <vector>
using std::vector;

int n = 1;

void test(string filename, int expected) {
	cout << "Case " << n << ": ";
	Matrix matrix = Matrix(filename);
	cout << endl << "Expected result: " << expected << endl;
	matrix.findLargestSubmatrix();
	cout << endl << endl;
	n++;
}

void runAllTests() {
	test("test1.txt", 0); // A matrix of all 0's
	test("test2.txt", 9); // A matrix of all 1's
	test("test3.txt", 1); // A matrix with a single 1 as the greatest rectangle
	test("test4.txt", 4); // A matrix with a greatest 1's square
	test("test5.txt", 6); // A matrix with a greatest  1's rectangle
	test("test6.txt", 3); // A matrix with a single colomn as its greatest submatrix
	test("test7.txt", 3); // A matrix with a single row as its greatest submatrix
	test("test8.txt", 4); // A matrix with a single greatest 1's rectangle
	test("test9.txt", 4); // A matrix with multiple, equal largest 1's rectangles
	test("test10.txt", 6); // A matrix with a multiple equal, overlapping greatest 1's rectangles
}