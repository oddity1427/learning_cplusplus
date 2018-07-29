//meant to test vectors, std::size_t
//from outside research, std::size_t should be used in basically every place that will be used as an index.
//it is a consistency as well as a security thing in larger programs.
//this program will take in space delimited integers and sort them with a simple bubble sort
//I know that bubble sort is wildly inefficient, but thats not the point of this test

#include <iostream>
#include <string>
//make sure that you include vector when you will actually be using it.
#include <vector>

int main(){
	//In the interest of time, I don't think it is necessary for these examples to be fully functional and modular
	//eg: sorts like these, I'm just going to make complete enough for me to tell that they basically work
	//I've already taken a data structures class, I don't really need to do all the projects again to learn c++
	std::cout << "enter space delimited numbers\n";
	//remember to define the type of the vector when declaring
	std::vector<int> v;
	int x;
	while(std::cin >> x){
		v.push_back(x);
	}
	std::cout << "\n";

	if(v.size() < 3){
		std::cout << "not enough numbers entered \n";
		return 1;
	}

	//now to sort
	bool sorted = false;
	int temp = 0;
	std::size_t i = 0;
	while(!sorted){
		sorted = true;
		i = 0;
		while(i < v.size() - 1){
			if(v[i] > v[i+1]){
				temp = v[i+1];
				v[i+1] = v[i];
				v[i] = temp;
				sorted = false;
			}
			i += 1;
		}
	}

	//now to print out
	i = 0;
	std::string s = "";
	while(i < v.size()){
		std::cout << v[i] << " ";
		i += 1;
	} 
	std::cout <<  "\n";

	return 0;
}