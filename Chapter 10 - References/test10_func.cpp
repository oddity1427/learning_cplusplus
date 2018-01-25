//Updates from last chapter:
//updated read_double_vector to work with references and output to more appropriate places
//Because of the way I wrote most of the sorting functions to all use iterators, I don't think It's going to be that useful to try and work references into those functions


#include "test09_head.hpp"
#include <iostream>
//need to include iterators if we're going to use them
#include <iterator>

//being able to call on "stream" makes everything look alot cleaner in addition to being faster as a reference to cin
//also nice that we do not have to call on cout really anymore
std::vector<double> read_double_vector(std::istream& stream){
	std::vector<double> input;
	double x;

	while(stream >> x){
		input.push_back(x);
	}

	if(!stream.eof()){
		stream.clear();
		std::string s;
		std::getline(stream,s);
		//no longer need to just print to console, we have a place for that now.
		std::cerr << "Error, following input not processed: " << s << "\n";
	}
	//clear the stream so this function can be called multiple times
	std::cin.clear();
	std::cin.ignore(10000,'\n');
	return input;
}

//basically just takes the vector input and breaks it into iterators for the actual sorting
std::vector<double> mergesort(std::vector<double> v){
	iterator start = v.begin();
	iterator end = v.end();
	while(!isSorted(start, end)){
		sort_implementation(start, end);
	}
	return v;
}

//takes two iterators to sort between
//slight inefficiency in checking if it is sorted each time
//works through and determines next 1 or two runs and merges them together until a pass has been completed between the beginning and end iterator
//not really a very good sort as implemented, worst case is basically an insertion sort
//only doing it this way because the obvious example of quicksort is taken and this should be reasonably complex
void sort_implementation(iterator start, iterator end){

	if(sorted(start, end)){
		return;
	}

	bool savedRun = false;
	iterator nextEnd;
	iterator lastStart;
	iterator lastEnd;
	lastEnd = start;

	while(true){
		nextEnd = run_end(lastEnd, end);

		//It turns out that this will be true whether or not there is a previously saved run.
		//If there is only 1 run, the vector is sorted and this will not be called so this will only ever be called with lastStart, LastEnd already defined if there are an odd number of runs
		if(end == nextEnd){			
			sort_merging(lastStart, lastEnd, nextEnd);
			return;
		}

		//This is the meat of taking the identified runs and merging them if necessary
		if(!savedRun){	
			lastStart = lastEnd;
			lastEnd = nextEnd;					
			savedRun = true;
		}else{
			sort_merging(lastStart, lastEnd, nextEnd);			
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
	iterator vec1Itr  = start;
	iterator vec2Itr  = mid; 
	std::vector<double> sorted;
	while(sorted.size() < end - start){			//not all of the elements are merged yet

		if(vec1Itr == mid){					//if one of the merge halfs is already exhausted, push the other one
			sorted.push_back(*vec2Itr);
			vec2Itr++;
		}else if(vec2Itr == end){
			sorted.push_back(*vec1Itr);
			vec1Itr++;
		}

		else if(*vec1Itr < *vec2Itr){			//push from the half which has a lower value at the head
			sorted.push_back(*vec1Itr);
			vec1Itr++;
		}else{
			sorted.push_back(*vec2Itr);
			vec2Itr++;
		}
	}

	for(double d : sorted){
		*start = d;
		start++;
	}
	
}

//helps sort_implementation, makes the code cleaner
bool isSorted(iterator start, iterator end){
	if(end-start == 1){
		return true;
	}
	start++;
	bool to_return = true;
	while(end != start ){
		if(*start < *(start - 1)){
			to_return = false;
		}
		start++;
	}
	return to_return;
}

//finds the end of the next run, is called a lot so separating to make cleaner
iterator run_end(iterator start, iterator end_itr){
	
	while(true){
		if( start + 1 == end_itr || *(start+1) < *start){
			return start + 1;
		}
		start++;
	}
	return start;
}

