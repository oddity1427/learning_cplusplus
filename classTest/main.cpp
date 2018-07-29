#include "Rectangle.hpp"
#include <iostream>

int main () {

  Rectangle rect (5,6);
  Rectangle rect2 (7,8);

  std::cout << rect.area() << std::endl;
  std::cout << rect2.area() << std::endl;

  return 0;
}