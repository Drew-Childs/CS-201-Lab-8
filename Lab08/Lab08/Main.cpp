//Drew Childs, Lab08
#include <iostream>
#include "Header.h"
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <math.h>
using namespace std;

int main() {
	double price;		//declaring variables
	string product;
	vector<double> DVD;
	vector<double> MUSIC;
	vector<double> TV;

	ifstream input_file("input.txt");		//opening files
	ofstream output_file("output.txt");

	while (input_file.good()) {			//reading data from input and storing it in appropriate vectors
		input_file >> product >> price;
		if (product == "DVD") {
			DVD.push_back(price);
		}
		else if (product == "TV") {
			TV.push_back(price);
		}
		else {
			MUSIC.push_back(price);
		}
	}
	
	try {		//Each category (DVD, TV, and MUSIC) all have their own try except blocks.
		output_file << "DVD\t" << total(DVD) << "\t" << median(DVD) << "\t" << mean(DVD) << endl;
	}
	catch (runtime_error) {
		output_file << "DVD\t" << total(DVD) << "\tnan\tnan" << endl;
	}

	try {		//if for some reason the size is zero, it'll return nan for both median and mean
		output_file << "TV\t" << total(TV) << "\t" << median(TV) << "\t" << mean(TV) << endl;
	}
	catch (runtime_error) {
		output_file << "TV\t" << total(TV) << "\tnan\tnan" << endl;
	}

	try {
		output_file << "MUSIC\t" << total(MUSIC) << "\t" << median(MUSIC) << "\t" << mean(MUSIC) << endl;
	}
	catch (runtime_error) {
		output_file << "MUSIC\t" << total(MUSIC) << "\tnan\tnan" << endl;
	}

	input_file.close();		//closing files
	output_file.close();
	return 0;
}