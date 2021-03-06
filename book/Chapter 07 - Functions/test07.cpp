//This program is meant to test implementation and integration of multiple functions. 

//This program will implement a similar input function to the example and then, treating the vector like a signal, implement a moving average filter over the data
//The program will work with doubles to be more precise when the filter is applied, and be more useful with any level of precision.

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iterator>

std::vector<double> read_double_vector();
int get_filter_width();
int read_int();

//It should be noted that std::cin and std::cout do not play nice together while on the same line
//when they are called they can flush data that was waiting to be printed.
int main(){

	//The following code is left as a record for what was ran in double_read_test.out
	// std::cout << "Enter data signal as space delimited doubles\n";
	// std::vector<double> v = read_double_vector();
	// for(double e : v){
	// 	std::cout << e << " ";
	// }
	// std::cout << "\n";

	//The following is commented as record of the code fun for filter_and_int_read_test.out
	// int example = read_int();
	// std::cout << example << "\n";
	// int width = get_filter_width();
	// std::cout << width << "\n";

	//Actual moving filter algorithm here
	//input
	std::vector<double> data;
	std::cout << "Enter the double data signal\n";
	data = read_double_vector();
	int width = get_filter_width();
	int length = data.size();

	//appropriately padding the data vector with 0s 
	int padding = width/2;
	for(int i = 0; i < padding; i++){
		data.push_back(0);
		data.insert(data.begin(),0);
	}

	//create filtered vector
	std::vector<double> filtered;
	double sum;
	for(int i = padding; i < padding + length; i++){
		sum = 0;
		for(int j = i - padding; j < i + padding; j++ ){
			sum += data[j];
		}
		filtered.push_back(sum / width); 
	}

	for(double d : filtered){
		std::cout << d << " ";
	}
	std::cout << "\n";

	
	return 0;
}

//gets the width of the filter to be applied
//rounds up to the nearest positive, odd int, greater than 1 (a moving filter of width 1 is redundant)
int get_filter_width(){

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
//given the scope of these problems, I don't think further user friendliness is needed
int read_int(){
	std::cout << "enter int\n";
	int num;
	
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
		std::cout << "\n";

	}
	
}

//I thought the way the example was set up was a litte bit messy
//the while(true)+break seemed like a bit extra for what was effectively a single if() decision
//simplified, modified to read in doubles
std::vector<double> read_double_vector(){
	std::vector<double> input;
	double x;

	while(std::cin >> x){
			input.push_back(x);
	}
	std::cout << "\n";

	if(!std::cin.eof()){
		std::cin.clear();
		std::string s;
		std::getline(std::cin,s);
		std::cout << "Error, following input not processed: " << s << "\n";
	}

	return input;
}