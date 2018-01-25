//This header is going to be fairly barebones
//I see the value of the header files a little bit more now in this section where everything is grouped together.
//I don't think that I'm going to change the iterator parameters to references to parameters, they're already pointers basically
#ifndef CHAPTER_09_TEST_HEADER
#define CHAPTER_09_TEST_HEADER

#include <vector>
#include <string>
#include <iterator>

using iterator = std::vector<double>::iterator;

//It is definitely an interesting feature to give a default value in the intialization
//going to have to get used to that but it definitely seems useful
std::vector<double> read_double_vector(std::istream& stream = std::cin);

std::vector<double> mergesort(std::vector<double> v);
void sort_implementation(iterator start, iterator end);
void sort_merging(iterator start, iterator mid, iterator end);
bool isSorted(iterator start, iterator end);
iterator run_end(iterator start, iterator end_itr);

#endif