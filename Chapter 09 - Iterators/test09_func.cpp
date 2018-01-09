//most of the sorting will be done with a main mergesort function just to make the vector passing easier,with sort_implementation and sort_merge doing the lifting with iterators
//I suspect that this algorithm will not take full advantage of the concept of iterators
//As I understand them, they mostly exist to make algorithms container independent, and allow for situationally cleaner and faster code. 
//I'm not trying to reinvent the wheel here for the purposes of a test, so I'm not going to try and implement an in place merge sort. 
//as a result of this I'm going to create sub vectors during the sorting process, somewhat defeating the purpose though I am not going to access any data outside of dereferencing an iterator

#include "test09_head.hpp"
#include <iostream>
//need to include iterators if we're going to use them
#include <iterator>


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
std::vector<double> mergesort(std::vector<double> v){
	while(!isSorted){
		sort_implementation(v.start(), v.end());
	}
	return v;
}

//takes two iterators to sort between
//slight inefficiency in checking if it is sorted each time
//works through and determines next 1 or two runs and merges them together until a pass has been completed between the beginning and end iterator
//not really a very good sort as implemented, worst case is basically an insertion sort
//only doing it this way because the obvious example of quicksort is taken and this should be reasonably complex
//WILL CRASH IF PASSED ALREADY SORTED LIST, a single run will be detected and there will be null pointers
//not a  problem if implemented with mergesort above
void sort_implementation(iterator start, iterator end){

	bool savedRun == false
	iterator nextEnd, lastStart, lastEnd;
	lastEnd = start

	while(;){
		nextEnd = run_end(lastEnd, end);

		//It turns out that this will be true whether or not there is a previously saved run.
		//If there is only 1 run, the vector is sorted and this will not be called so this will only ever be called with lastStart, LastEnd already defined if there are an odd number of runs
		if(end - nextEnd < 1){			
			sort_merging(lastStart, LastEnd, nextEnd);
			return;
		}

		//This is the meat of taking the identified runs and merging them if necessary
		if(!savedRun){	
			lastStart = lastEnd;
			lastEnd = nextEnd;					
			savedRun = true;
		}else{
			sort_merging(lastStart, LastEnd, nextEnd);			
			lastStart = lastEnd;
			lastEnd = nextEnd;
			savedRun = false;
		}
	}
	
	
}

//actually does the merging algorithm between two contiguous runs noted by 3 iterators
//this is where this becomes a bit weird, as I have to sort into a vector and then copy back to the original with the iterators
//There is definitely a way to use this to also check if the vector is sorted using the number of runs, If I was actually going to use this I would remove that inefficiency
void sort_merging(iterator start, iterator mid, iterator end){
	iterator 1vecItr  = start;
	iterator 2vecItr  = mid; 
	std::vector<double> sorted;
	while(sorted.size() < end - start){			//not all of the elements are merged yet

		if(1vecItr - mid < 1){					//if one of the merge halfs is already exhausted, push the other one
			sorted.push_back(2vecItr*);
			2vecItr++;
		}else if(2vecItr - end < 1){
			sorted.push_back(1vecItr*);
			1vecItr++;
		}

		else if(1vecItr* < 2vecItr*){			//push from the half which has a lower value at the head
			sorted.push_back(1vecItr*);
			1vecItr++;
		}else{
			sorted.push_back(2vecItr*);
			2vecItr++;
		}
	}
	
}

//helps sort_implementation, makes the code cleaner
bool isSorted(iterator start, iterator end){
	bool to_return = true;
	while(start != end){
		if(start* < (start - 1)*){
			to_return = false;
		}
		start++;
	}
	return to_return;
}

//finds the end of the next run, is called a lot so separating to make cleaner
iterator run_end(iterator start, end_itr){
	//huh neat this is while(true){}
	while(;){
		if(start + 1 == end_itr || (start+1)* < start*){
			return start + 1;
		}
		start++;
	}
	return start;
}

