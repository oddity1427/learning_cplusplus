//meant to test (e:v) notation, iterative for loop notation, as well as the auto 'type'
//None of this is significantly new or different over the last section, so much like the examples I am going to tweak the chapter05 test to include this chapters elements

#include <iostream>
#include <vector>

int main(){
	
	std::cout << "enter space delimited numbers\n";
	std::vector<int> v;
	int x;
	while(std::cin >> x){
		v.push_back(x);
	}
	std::cout << "\n";

	if(v.size() < 2){
		std::cout << "not enough numbers entered \n";
		return 1;
	}

	//now to sort
	bool sorted = false;
	int temp = 0;
	
	while(!sorted){
		sorted = true;
		for(std::size_t i = 0;i < v.size() - 1; i++){
			if(v[i] > v[i+1]){
				temp = v[i+1];
				v[i+1] = v[i];
				v[i] = temp;
				sorted = false;
			}
		}
	}

	int total = 0;
	for(int e:v){
		total += e;
	}

	double average = total/v.size();

	//now to print out
	bool printed = false;
	for(std::size_t i = 0;i < v.size() - 1; i++){
		std::cout << v[i] << " ";
		//this conditional would throw an error if both were evaluated and the 2nd one wasn't skipped after the first evaluated as false
		if(!printed && v[i+1] > average){
			std::cout << "(" << average << ") ";
			printed = true;
		}
	} 
	std::cout <<  "\n";

	return 0;
}