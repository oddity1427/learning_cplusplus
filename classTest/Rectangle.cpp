#ifndef RECTANGLE_CPP_FLAG
#define RECTANGLE_CPP_FLAG

#include "Rectangle.hpp"

Rectangle::Rectangle(int a, int b){
	width = a;
	height = b;
}

int Rectangle::area(){
	return (width * height);
}

#endif