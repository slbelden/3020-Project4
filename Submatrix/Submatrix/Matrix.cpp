// Stephen Belden
// Meghan Haukaas
// Chris Ruiz?

// 2015-Nov-19

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <stack>
#include "Matrix.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::stack;
using std::ifstream;
using std::default_random_engine;
using std::uniform_int_distribution;

Matrix::Matrix() {}

Matrix::Matrix(string filename) {
	ifstream infile;
	infile.open(filename.c_str());
	if(infile) {
		cout << "Loading matrix from file..." << endl;
		while(!infile.eof()) {
			string row;
			getline(infile, row);
			row.c_str();
			vector<int> temp;
			for each(char c in row) {
				temp.push_back((c == '1') ? 1 : 0);
			}
			data.push_back(temp);
		}
		print();
	}
	else {
		cout << "Error: could not open file" << endl;
	}
}

void Matrix::randomGenerate(int n) {
	if(data.size() >= 1) {
		cout << "ERROR: This matrix already contains data" << endl
			<< "Please create a new matrix object." << endl;
	}
	else {
		default_random_engine generator;
		uniform_int_distribution<int> distribution(0, 1);
		for(int i = 0; i < n; i++) {
			vector<int> temp;
			for(int j = 0; j < n; j++) {
				temp.push_back(distribution(generator));
			}
			data.push_back(temp);
		}
		cout << "Generated Matrix:" << endl;
		print();
	}
}

void Matrix::print() const {
	for each(vector<int> v in data) {
		for each(int i in v) {
			cout << i;
		}
		cout << endl;
	}
}

int Matrix::findLargestSubmatrix() const {
	if(data.size() <= 0) {
		cout << "ERROR: This matrix contains no data" << endl
			<< "Please create a non-empty matrix first." << endl;
		return 0;
	}
	else {
		// Initialize histogram matrix
		// Row one is always equal to the input
		vector<vector<int>> C{data[0]};
		for(size_t M = 1; M < data.size(); M++) {
			vector<int> row;
			for(size_t N = 0; N < data[M].size(); N++) {
				// Histogram entries represent the number of contiguous 1s
				// above and including the current 1. Zeros always = 0.
				if(data[M][N] == 1) row.push_back(data[M][N] + C[M - 1][N]);
				else row.push_back(0);
			}
			C.push_back(row);
		}

		// Test Print
		cout << endl << "Histogram Matrix:" << endl;
		for each(vector<int> v in C) {
			for each(int i in v) cout << i;
			cout << endl;
		}
		
		stack<vector<int>> pairs; // Initialize stack of pairs for tests
		pairs.push(vector<int>{0, -1}); // Add buffer entry
		size_t best = 1; // Initialize largest submatrix size

		// Test for largest submartix row-by-row, element-by-element
		for(size_t row = 0; row < C.size(); row++) {
			for(size_t i = 0; i < C[row].size(); i++) {

			}
		}


		return 1;
	}
}
