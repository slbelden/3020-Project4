// Stephen Belden
// Meghan Haukaas
// Chris Ruiz?

// 2015-Nov-19

#include <iostream>
#include <string>
#include <vector>
#include "Matrix.h"
#include "Tests.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;

int main() {
	while(1) {
		string command;
		cout << "Select an option:" << endl
			<< "\t R - Use a Randomly generated a N x N matrix" << endl
			<< "\t F - Open a text File containg a matrix of 0s and 1s" << endl
			<< "\t T - Run pre-defined Test cases" << endl
			<< "\t H - Help" << endl
			<< "\t E - Exit" << endl
			<< "Type a single letter and press enter: ";
		getline(cin, command);

		if(command.substr(0, 1) == string("r") || command.substr(0, 1) == string("R")) {
			int num;
			cout << "Input size of the square matrix edge (IE: Input \"N\" in N x N matrix): ";
			cin >> num;
			cout << "Generating " << num << " x " << num << " matrix:" << endl;
			Matrix M = Matrix();
			M.randomGenerate(num);
			M.findLargestSubmatrix();
		}

		if(command.substr(0, 1) == string("f") || command.substr(0, 1) == string("F")) {
			string filename;
			cout << "Enter a filename: ";
			getline(cin, filename);
			Matrix M = Matrix(filename);
			M.findLargestSubmatrix();
		}

		if(command.substr(0, 1) == string("t") || command.substr(0, 1) == string("T")) {
			cout << "Running test cases..." << endl;
			runAllTests();
		}

		if(command.substr(0, 1) == string("h") || command.substr(0, 1) == string("H")) {
			cout << endl
				<< "This program finds the largest submartix of ones in an N x N matrix." << endl
				<< "\tThe input matrix must be square" << endl
				<< "\tThe output matrix can be square or rectangular" << endl
				<< endl;

			cout << "Note: This program reports element positions in matrix form:" << endl
				<< "\tIndices start at 1, not at 0" << endl
				<< "\tLocations are given by two numbers in the form: (M x N)" << endl
				<< "\tM is the vertical location, starting from the top and going down" << endl
				<< "\tN is the horizontal location, starting from the left and going right" << endl
				<< endl;

			cout << "This program can accept .txt files as input (option F)" << endl
				<< "\tThe matrix must be N x N, IE: having the same height and width" << endl
				<< "\tRows of the matrix must be given without spaces" << endl
				<< "\tColumns of the matrix are denoted by new lines" << endl
				<< "\tThere must NOT be a newline character at te end of the file" << endl
				<< "\tExample file:" << endl
				<< "\t010\n\t100\n\t110" << endl;
		}

		if(command.substr(0, 1) == string("e") || command.substr(0, 1) == string("E")) {
			exit(0);
		}

		cout << endl << endl;
	}
}