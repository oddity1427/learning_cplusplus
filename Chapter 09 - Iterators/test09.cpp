//testing the use of iterators to do sorting in a vector
//will be implementing a slightly smarter merge sort, taking advantage of natural runs
//Not going to be implementing any sort of searching, I figure this will be more than enough to get iterators down.

#include "test09_head.hpp"
#include <iostream>

int main(){
	std::string s = "Input space delimited doubles, ctrl+d to exit in terminal";
	std::vector<double> input = read_double_vector(s);
	std::cout << "mergesort used to sort input, displayed sorted below";
	std::vector<double> sorted = mergesort(input);
	for(double d : sorted){
		std::cout << d << " ";
	}
	std::cout << "\n";
}