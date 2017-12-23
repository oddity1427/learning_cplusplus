//here is where all of the vector functions will be defined that are used in test08.cpp
//I decided that for the sake of terminal input consistency that I would do away with the int input functions and just read any additional data in at the beginning of the double vector
//If I need other datatypes, I think I will make a copy of this function but with that type just so everything is consistent.

//NOTE: it is quotes when you are including another file by name and not <>
#include "test08.h"
#include <iostream>


//same as the previous chapter but modified to take a std::string message in to display
//this should make it look marginally cleaner
std::vector<double> read_double_vector(std::string m){
	std::vector<double> input;
	double x;

	std::cout << m << "\n";

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

std::vector<double> greater_vector(double level, std::vector<double> input){
	double greater;
	for(double d : input){
		if(d > level){
			greater.push_back(d);
		}
	}
	return greater;
}

int get_filter_width(int w){
	if(w < 3){
		w = 3;
	}else if(w % 2 == 0){
		w++;
	}
	
	return w;
}

//I decided that it would be better to read in ints using the double read function than to have a separate algorithm
//This means all input will seem consistent from the users point of view
int read_int(std::string m){
	std::vector<double> input = read_double_vector(m);
	//I know that this isn't the best way to cast things but for double to int, this should be sufficient
	int fromVect = (int) input[0];
	return fromVect;
}

//moved from main(), probably should have been its own function before anyway
std::vector<double> moving_average(std::vector<double> data, int filter_width){
	//appropriately padding the data vector with 0s 
	int padding = filter_width/2;
	for(int i = 0; i < padding; i++){
		data.push_back(0);
		//I didn't say so before but I had to peek at iterators online to make this not overly complex
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
	return filtered;
}

