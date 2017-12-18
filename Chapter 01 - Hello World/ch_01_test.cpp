//This should be just a basic test to make sure I have the syntax right for creating a main method
//Should spit out hello world plus some additional text

//NOTE: function to compile is the following line
// g++ -std=c++11 code_name -o program_name

#include <iostream>

int main() {

	std::cout  << "Hello World! I'm C++\n";

	std::cout << "this" << "should" << "all" << "be" << "piped" << "together\n";

	std::cout << "next line should be printed as '42' \n";

	std::cout << 2 * 20 + 2 << "\n";


	return 0;
}