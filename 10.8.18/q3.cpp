#include <iostream>


int pow(int base, int timesToMultiply) {
	if(timesToMultiply <= 1){
		return base;
	}
	timesToMultiply -= 1; 			//taking step closer to end condition
	return base*pow(base, timesToMultiply);
}

int main() {
	int base;
	int exponent;					// intializing the variables

	std::cout << "Please input a base\n";
	std::cin >> base;
	std::cout << "Please input an exponent\n";
	std::cin >> exponent;			//getting input from user

	if(base < 1 || exponent < 1) {	// checking for negatives
		std::cout << "Both inputs should be positive\n";
		return 0; 
	}
	std::cout << pow(base,exponent)<<"\n";	// Printing result
	return 0;
}