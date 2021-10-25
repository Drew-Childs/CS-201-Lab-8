//Drew Childs, Lab08
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

vector<double> sorting(vector<double> inputVec) {
	sort(inputVec.begin(), inputVec.end());		//Using this function from a previous lab, but I thought I would still give credit
	return inputVec;							//to where I found it originally: http://www.cplusplus.com/reference/algorithm/sort/
}

double total(vector<double> inputVec) {
	double total = 0;
	for (unsigned i = 0; i < inputVec.size(); i++) {		//finds total for vector passed to function
		total += inputVec.at(i);
	}
	return total;
}

double mean(vector<double> inputVec) {
	if (inputVec.size() == 0) {				//makes sure size of vector isn't zero
		throw runtime_error("Error");
	}
	return (total(inputVec) / inputVec.size());		//returns average
}

double median(vector<double> inputVec) {
	if (inputVec.size() == 0) {				//makes sure size of vector isn't zero
		throw runtime_error("Error");
	}
	else {
		inputVec = sorting(inputVec);
		if (inputVec.size() % 2 == 0) {		//returns median of even sized vector
			return (inputVec.at(inputVec.size() / 2) + inputVec.at((inputVec.size() / 2) - 1)) / 2;
		}
		else {		//returns median for odd sized vector
			return inputVec.at(inputVec.size() / 2);
		}
	}
}