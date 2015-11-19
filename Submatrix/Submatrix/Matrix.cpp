// Stephen Belden
// Meghan Haukaas
// Chris Ruiz?

// 2015-Nov-19

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include "Matrix.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;
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
	cout << "Largest Submatrix of Ones has area: N" << endl;
	return 0;
}