//testing to make sure I understand how to take input and declare variables
//input less important
//gong to try and declare all sorts of variables to see if they will compile

//make sure all required libraries are included
#include <iostream>
#include <string>
//NOTE: after trying to compile otherwise, compiler gives a warning for trying to compile with a semicolon at the end of preprossesor derectives.


//main starts the actual program.
//NOTE: it is std::cout and std::cin NOT std::out and std::in
int main(){
	double x = 0;
	int y = 4;
	char z = 'b';

	//it is my understanding currently that string literals ("string") are actually char arrays and I've not been told that yet.
	std::string s;

	//basic example of i/o with double
	std::cout << "Input the number to be doubled\n";
	std::cin >> x;
	x = 2 * x;
	std::cout << "twice that number is " << x << "\n";

	//making sure that still works with std::strings
	std::cout << "input a string to load in\n";
	std::cin >> s;
	std::cout << "wow, very impressive, you entered: " << s << "\n";
	//NOTE: this std::cin method will only read up to the first whitespace when you read in
	//other methods must be used for parsing line by line

	//outputting all of the other variables that were loaded in while we're at it
	std::cout << "the char and letter that were hardcoded were: " <<  z << y <<"\n";

	return 0;
}