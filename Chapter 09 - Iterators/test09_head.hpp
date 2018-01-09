//This header is going to be fairly barebones
//At this point I don't see a real advantage at this scale to using these header files
//But I will keep including them as best practice
#ifndef CHAPTER_09_TEST_HEADER
#define CHAPTER_09_TEST_HEADER

#include <vector>
#include <string>
#include <iterator>

//this will just simplify having to type all of that out over and over
using iterator = std::vector<double>::iterator;

std::vector<double> read_double_vector(std::string m);
std::vector<double> mergesort(std::vector<double> v);
void sort_implementation(iterator start, iterator end);
void sort_merging(iterator start, iterator mid, iterator end);
bool isSorted(iterator start, iterator end);
iterator run_end(iterator start, end_itr);

#endif