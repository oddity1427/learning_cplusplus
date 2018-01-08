//most of the sorting will be done with a main mergesort function just to make the vector passing easier,with sort_implementation and sort_merge doing the lifting with iterators
//I suspect that this algorithm will not take full advantage of the concept of iterators
//As I understand them, they mostly exist to make algorithms container independent, and allow for situationally cleaner and faster code. 
//I'm not trying to reinvent the wheel here for the purposes of a test, so I'm not going to try and implement an in place merge sort. 
//as a result of this I'm going to create sub vectors during the sorting process, somewhat defeating the purpose though I am not going to access any data outside of dereferencing an iterator

#include "test08.h"
#include <iostream>
//need to include iterators if we're going to use them
#include <iterator>

//this will just simplify having to type all of that out over and over
using iterator = std::vector<double>::iterator


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
	//clear the stream so this function can be called multiple times
	std::cin.clear();
    std::cin.ignore(10000,'\n');
	return input;
}

//basically just takes the vector input and breaks it into iterators for the actual sorting
std::vector<double> mergesort(std::vector<double>){

}

//takes two iterators to sort between
//slight inefficiency in checking if it is sorted each time
//works through and determines next 1 or two runs and merges them together until a pass has been completed between the beginning and end iterator
//then calls itself again
//not really a very good sort as implemented, worst case is basically an insertion sort
//only doing it this way because the obvious example of quicksort is taken and this should be reasonably complex
void sort_implementation(iterator start, iterator end){

}

//actually does the merging algorithm between two contiguous runs noted by 3 iterators
//this is where this becomes a bit weird, as I have to sort into a vector and then copy back to the original with the iterators
void sort_merging(iterator start, iterator mid, iterator end){

}

//hleps sort_implementation, makes the code cleaner
bool isSorted(iterator start, iterator end){

}

//finds the end of the next run, is called a lot so separating to make cleaner
iterator run_end(iterator start, end_itr){

}
