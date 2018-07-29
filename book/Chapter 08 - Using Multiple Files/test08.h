//#define acts as a preprocessor flag to make sure that the following is only looked at by the preprocessor once
//everything in the #ifndef/#endif block will be erased after the first read
#ifndef CHAPTER_08_HEADER

#define CHAPTER_08_HEADER

#include <vector>
#include <string>

std::vector<double> read_double_vector(std::string m);

std::vector<double> greater_vector(double level, std::vector<double> input);

int get_filter_width(int w);

int read_int(std::string m);

std::vector<double> moving_average(std::vector<double> data, int filter_width);



//Not doing anything inline because I looked at it online and I don't think that anything I'll be doing warrants it
//Any speed increases are going to be totally unnoticable anyway and its not worth bugs or crashes.
#endif