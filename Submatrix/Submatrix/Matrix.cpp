// Stephen Belden
// Meghan Haukaas

// 2015-Dec-06

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
		printMatrix();
	}
	else {
		cout << "Error: could not open file" << endl;
	}
}

Matrix::Matrix(vector<vector<int>> input) {
	// Input validation
	int rowLength = input[0].size();
	for each (vector<int> row in input) {
		if(row.size() != rowLength) {
			cout << "ERROR: Tried to create a matrix object with invalid dimentions" << endl;
			exit(1);
		}
		for each (int n in row) {
			if(n != 1 && n != 0) {
				cout << "ERROR: Tried to create a matrix object from invalid data" << endl;
				exit(1);
			}
		}
	}
	data = input;
}

void Matrix::randomGenerate(int n) {
	if(data.size() >= 1) {
		cout << "ERROR: This matrix already contains data" << endl
			<< "Please create a new matrix object." << endl;
	}
	else {
		silentRandomGenerate(n);
		cout << "Generated Matrix:" << endl;
		printMatrix();
	}
}

void Matrix::silentRandomGenerate(int n) {
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
	}
}

void Matrix::printMatrix() const {
	for each(vector<int> v in data) {
		for each(int i in v) {
			cout << i;
		}
		cout << endl;
	}
}

void Matrix::printAnswer() const {
	if(LSO < 0) findLargestSubmatrix();
	if(LSO >= 0) cout << "Largest submatrix has size " << LSO << endl;
}

int Matrix::findLargestSubmatrix() const {
	if(data.size() <= 0) {
		cout << "ERROR: This matrix contains no data" << endl
			<< "Please create a non-empty matrix first." << endl;
		return 0;
	}
	else {
		// Initialize histogram matrix
		// Row one is always equal to the input, with a buffer zero at the end
		vector<vector<int>> histogram{data[0]};
		histogram[0].push_back(0);
		for(size_t M = 1; M < data.size(); M++) {
			vector<int> row;
			for(size_t N = 0; N < data[M].size(); N++) {
				// Histogram entries represent the number of contiguous 1s
				// above and including the current 1. Zeros always = 0.
				if(data[M][N] == 1) row.push_back(data[M][N] + histogram[M - 1][N]);
				else row.push_back(0);
			}
			row.push_back(0);
			histogram.push_back(row);
		}
		
		stack<vector<int>> pairs; // Initialize stack of pairs for tests
		pairs.push(vector<int>{0, -1}); // Add buffer entry
		size_t best = 0; // Initialize largest submatrix size

		// Test for largest submartix row-by-row, element-by-element
		for(size_t row = 0; row < histogram.size(); row++) {
			for(size_t i = 0; i < histogram[row].size(); i++) {
				if(histogram[row][i] > pairs.top()[0])
					pairs.push(vector<int>{histogram[row][i], (int)i});
				else {
					int prevI;
					while(histogram[row][i] < pairs.top()[0]) {
						prevI = pairs.top()[1];
						int prevH = pairs.top()[0];
						pairs.pop();
						if((i - prevI)*prevH > best)
							best = (i - prevI)*prevH;
					}
					if(histogram[row][i] > pairs.top()[0])
						pairs.push(vector<int>{histogram[row][i], prevI});
				}
			}
			while(!pairs.empty()) pairs.pop();
			pairs.push(vector<int>{0, -1}); // Add buffer entry
		}
		LSO = best;
		return best;
	}
}
