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
	/*
	// Case 1
	// A matrix of all 0's
	Matrix matrix1 = Matrix("test1.txt");
	cout << "Case 1: " << endl;
	matrix1.print();
	cout << endl << "Expected result: 0" << endl;
	matrix1.findLargestSubmatrix();
	cout << endl << endl;

	// Case 2
	// A matrix of all 1's
	Matrix matrix2 = Matrix("test2.txt");
	cout << "Case 2: " << endl;
	matrix2.print();
	cout << endl << "Expected result: 9" << endl;
	matrix2.findLargestSubmatrix();
	cout << endl << endl;

	// Case 3
	// A matrix with a single 1 as the greatest rectangle
	Matrix matrix3 = Matrix("test3.txt");
	cout << "Case 3: " << endl;
	matrix3.print();
	cout << endl << "Expected result: 1" << endl;
	matrix3.findLargestSubmatrix();
	cout << endl << endl;

	// Case 4
	// A matrix with a greatest 1's square
	Matrix matrix4 = Matrix("test4.txt");
	cout << "Case 4: " << endl;
	matrix4.print();
	cout << endl << "Expected result: 4" << endl;
	matrix4.findLargestSubmatrix();
	cout << endl << endl;

	// Case 5
	// A matrix with a greatest  1's rectangle
	Matrix matrix5 = Matrix("test5.txt");
	cout << "Case 5: " << endl;
	matrix5.print();
	cout << endl << "Expected result: 6" << endl;
	matrix5.findLargestSubmatrix();
	cout << endl << endl;

	// Case 6
	// A matrix with a single colomn as its greatest submatrix
	Matrix matrix6 = Matrix("test6.txt");
	cout << "Case 6: " << endl;
	matrix6.print();
	cout << endl << "Expected result: 3" << endl;
	matrix6.findLargestSubmatrix();
	cout << endl;

	// Case 7
	// A matrix with a single row as its greatest submatrix
	Matrix matrix7 = Matrix("test7.txt");
	cout << "Case 7: " << endl;
	matrix7.print();
	cout << endl << "Expected result: 3" << endl;
	matrix7.findLargestSubmatrix();
	cout << endl << endl;

	// Case 8
	// A matrix with a single greatest 1's rectangle
	Matrix matrix8 = Matrix("test8.txt");
	cout << "Case 8: " << endl;
	matrix8.print();
	cout << endl << "Expected result: 4" << endl;
	matrix8.findLargestSubmatrix();
	cout << endl << endl;

	// Case 9
	// A matrix with multiple, equal largest 1's rectangles
	Matrix matrix9 = Matrix("test9.txt");
	cout << "Case 9: " << endl;
	matrix9.print();
	cout << endl << "Expected result: 4" << endl;
	matrix9.findLargestSubmatrix();
	cout << endl << endl;

	// Case 10
	// A matrix with a multiple equal, overlapping greatest 1's rectangles
	Matrix matrix10= Matrix("test10.txt");
	cout << "Case 10: " << endl;
	matrix10.print();
	cout << endl << "Expected result: 6" << endl;
	matrix10.findLargestSubmatrix();
	cout << endl << endl;
	*/

	test("test1.txt", 0);
	test("test2.txt", 9);
	test("test3.txt", 1);
	test("test4.txt", 4);
	test("test5.txt", 6);
	test("test6.txt", 3);
	test("test7.txt", 3);
	test("test8.txt", 4);
	test("test9.txt", 4);
	test("test10.txt", 6);
}