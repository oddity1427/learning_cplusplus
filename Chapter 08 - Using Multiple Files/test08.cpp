//testing the use of additional header and function files
//Will create a moving average of an input signal of specified width
//Then will make a vector of all values from the filtered signal above a threshold
//Not super useful, but I figured I should add more complexity when I rewrite the same code.

#include "test08.h"
#include <iostream>

int main(){
	//This code was copy pasted from chapter 07 and then modified to work with the updates in structure in this chapter.
	
	//This looks a lot cleaner after using all of the functions that have been added
	std::string double_message = "Enter the double data signal";
	std::vector<double> data = read_double_vector(double_message);
	
	std::string filter_message = "Enter the odd filter width, only the first value will be recorded";
	int width = get_filter_width(read_int(filter_message));

	std::string level_message = "enter filter threshold, only the first value will be recorded";
	int threshold = read_int(level_message);


	std::vector<double> mov_average = moving_average(data, width);

	for(double d : mov_average){
		std::cout << d << " ";
	}
	std::cout << "\n";

	std::vector<double> above_level = greater_vector(threshold, mov_average);

	for(double d : above_level){
		std::cout << d << " ";
	}
	std::cout << "\n";

	//no need to return 0, thanks compiler
}