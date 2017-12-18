//topics covered: if/elseif/else statements, std::cin/cout resolution
//this program should be able to take in user input and evaluate it

#include <iostream>
#include <string>

int main(){
	//NOTE: remember to declare all of the integers before they are used
	//NOTE: this is valid syntax for declaring and setting multiple vars
	int a,b,c,d = 0;
	std::cout << "enter four integers separated by spaces\n";
	//checking that cin resolves for all of the expected inputs
	if(std::cin >> a >> b >>c >>d){
		a = a * b;
		c = c * d;

		//if/else if /else are super basic, so not gonna make a huge tree here
		if(a > c){
			std::cout << "the product of the first two was greater than the product of the second two\n";
		}else if(a < c){
			std::cout << "the product of the first two was less than the product of the second two\n";
		}else{
			std::cout << "the product of the first two and the second two were equal\n";
		}

	}else{
		//failure case for cin resolution
		std::cout << "some part of the input was not correct\n";
		return 1;
	}
	return 0;
}