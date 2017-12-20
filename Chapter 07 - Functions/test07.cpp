//This program is meant to test implementation and integration of multiple functions. 

//This program will implement a similar input function to the example and then, treating the vector like a signal, implement a moving average filter over the data
//The program will work with doubles to be more precise when the filter is applied, and be more useful with any level of precision.

#include <iostream>
#include <vector>
#include <string>

//apparently its REQUIRED that you declare the functions up front, didn't realize that from the example
std::vector<double> read_double_vector();

int main(){
	std::cout << "Enter data signal as space delimited doubles\n";
	std::vector<double> v = read_double_vector();
	for(double d : v){
		std::cout << d << " ";
	}
	std::cout << "\n";
	return 0;
}

//I thought the way the example was set up was a litte bit messy
//the while(true)+break seemed like a bit extra for what was effectively a single if() decision
//simplified, removed success comment
std::vector<double> read_double_vector(){
	std::vector<double> input;
	int x;

	while(std::cin >> x){
			input.push_back(x);
	}
	//return to next line so next print statement does not follow on same line as input
	std::cout << "\n";

	if(!std::cin.eof()){
		std::cin.clear();
		std::string s;
		std::getline(std::cin,s);
		std::cout << "Error, following input not processed: " << s << "\n";
	}

	return input;
}