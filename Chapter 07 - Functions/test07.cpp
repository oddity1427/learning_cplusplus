//This program is meant to test implementation and integration of multiple functions. 

//This program will implement a similar input function to the example and then, treating the vector like a signal, implement a moving average filter over the data
//The program will work with doubles to be more precise when the filter is applied, and be more useful with any level of precision.

#include <iostream>
#include <vector>
#include <string>
#include <limits>

std::vector<double> read_double_vector();
int get_filter_width();
int read_int();

//It should be noted that std::cin and std::cout do not play nice together while on the same line
//when they are called they can flush data that was waiting to be printed.
int main(){
	//std::cout << "Enter data signal as space delimited doubles\n";
	//std::vector<double> v = read_double_vector();
	
	std::cout << read_int();
	std::cout << "\n";
	std::cout << get_filter_width();
	std::cout << "\n";
	//int width = get_filter_width();

	
	return 0;
}

//gets the width of the filter to be applied
//rounds up to the nearest positive, odd int, greater than 1 (a moving filter of width 1 is redundant)
int get_filter_width(){
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "enter the int width of the filter (should be odd and positive)\n";
	int w = read_int();
	if(w < 3){
		w = 3;
	}else if(w % 2 == 0){
		w++;
	}
	
	return w;
}

//probably going to have to read ints in the future as well so might as well not duplicate writing this as well
//has the problem that if the user has issues entering a number, will continuously expect one
//given the scope of these problems, I don't think further error checking/user friendliness is needed
int read_int(){
	std::cout << "enter int\n";
	int num;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while(true){
		if(std::cin >> num){
			
			return num;
		}else{
			//tell the user more input is expected and clear the error;
			std::cout << "that was not a valid input, try again";
			std::cin.clear();
			std::string s;
			std::getline(std::cin,s);
		}

	}
	
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