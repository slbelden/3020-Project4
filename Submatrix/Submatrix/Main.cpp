// Stephen Belden
// Meghan Haukaas

// 2015-Dec-06

#include <iostream>
#include <string>
#include <vector>
#include "Matrix.h"
#include "Tests.h"
#include "winTimer.h"
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
			<< "\t C - Run time Complexity analysis" << endl
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
			M.printAnswer();
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

		if(command.substr(0, 1) == string("c") || command.substr(0, 1) == string("C")) {
			cout << "This code will run until one problem takes more than 30 seconds..."
				<< endl << endl;
			for(int i = 1; i <= 3; i++) {
				cout << endl << "Finding the largest submatrix of ones with ";
				switch(i) {
				case 1:
					cout << "random input : " << endl;
					break;
				case 2:
					cout << "a matrix of all ones" << endl;
					break;
				case 3:
					cout << "a matrix of all zeros" << endl;
					break;
				}
				double lastRunTime = 0.0;
				size_t n = 1;
				do {
					Timer time;
					Matrix M;
					cout << "\tRunning with an input size of " << n << "x" << n
						<< ((n <= 9) ? " \t" : "\t") << "took ";
					if(i == 1) M.silentRandomGenerate(n);
					else if(i == 2) {
						vector<vector<int>> ones;
						for(size_t i = 0; i < n; i++) {
							vector<int> row;
							for(size_t j = 0; j < n; j++) {
								row.push_back(1);
							}
							ones.push_back(row);
						}
						M = Matrix(ones);
					}
					else if(i == 3) {
						vector<vector<int>> zeros;
						for(size_t i = 0; i < n; i++) {
							vector<int> row;
							for(size_t j = 0; j < n; j++) {
								row.push_back(0);
							}
							zeros.push_back(row);
						}
						M = Matrix(zeros);
					}
					time.start();
					M.findLargestSubmatrix();
					time.stop();
					cout << time() << " seconds" << endl;
					lastRunTime = time();
					n *= 2;
				} while(lastRunTime < 30.0);
			}
		}

		if(command.substr(0, 1) == string("h") || command.substr(0, 1) == string("H")) {
			cout << endl;
			for(int i = 0; i < 80; i++) cout << "/";
			cout << "This program finds the largest submartix of ones in a M x N matrix." << endl
				<< "\tThe input and output matrices can be square or rectangular." << endl
				<< "\tThe algorithm to find a largest submatrix of ones runs in O(M*N)" << endl
				<< "\tThis program does NOT report the location of the matrix it finds." << endl
				<< endl;

			cout << "This program can accept .txt files as input (option F)" << endl
				<< "\tRows of the matrix must be given without spaces" << endl
				<< "\tColumns of the matrix are denoted by new lines" << endl
				<< "\tThere must NOT be a newline character at the end of the file" << endl
				<< "\tExample:" << endl
				<< "\t010\n\t100\n\t110" << endl
				<< endl;
			for(int i = 0; i < 80; i++) cout << "/";
		}

		if(command.substr(0, 1) == string("e") || command.substr(0, 1) == string("E")) {
			exit(0);
		}

		cout << endl << endl;
	}
}