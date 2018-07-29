//mainly testing while loops
//should be able to reverse the words entered via std::cin
//I should probably do some way of testing to see if there is anything left on the input
//empty stream did not work as a terminator in the previous test.

#include <iostream>
#include <string>

int main(){
	std::string t,s = "";
	std::cout << "enter space delimited strings to be reversed\n";
	while(std::cin >> t){
		//this if statement is necessary to escape the std::cin empty stream not returning false
		if(t == "_"){
			break;
		}
		s = t + " " + s;
	}
	std::cout << s << "\n";
	return 0;
}