//The purpose of test10 will be to adapt the mergesort from test09 to be beter written using references and costants.
//also will be implementing similar changes to the example in this section to make the program more generalized and usable.
//Most of the rest of the code in this chapter will be therefor copy pasted from the last one.

//we do not need to change that much here as all of the meaningful changes will be made to the functions themselves. 

#include "test10.hpp"

int main(){
	//changed input to reflect that I am no longer passing in a string, and manually sending the message instead
	std::cout << "Input space delimited doubles, ctrl+d to exit in terminal\n";
	std::vector<double> input = read_double_vector();
	//newline for clarity after the input
	std::cout << "\n";
	std::cout << "mergesort used to sort input, displayed sorted below \n";
	std::vector<double> sorted = mergesort(input);
	for(double d : sorted){
		std::cout << d << " ";
	}
	std::cout << "\n";
}