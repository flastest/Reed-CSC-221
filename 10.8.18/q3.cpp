#include <iostream>

// Calculates base multiplied by itself timesToMultiply
// amount of times. Returns base to the power of
// timesToMultiply
int pow(int base, int timesToMultiply) {
	if(timesToMultiply <= 1){
		return base;
	}
	timesToMultiply -= 1; 			//taking step closer to end condition
	return base*pow(base, timesToMultiply);
}

//from Eitan:
// The main function should read in two integer values from the user. 
// If either input is less than 1, the main function should print out 
// "Both inputs must be positive" and return. If both inputs are 
// positive, the main function should call pow, specifying the first 
// user input as the first argument (i.e. base) and the second user 
// input as the second argument (i.e. exponent). The main function 
// should then print the result returned by pow before returning.
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