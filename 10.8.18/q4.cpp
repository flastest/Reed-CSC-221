#include <iostream>


// Logarithm function takes 2 inputs, base and num
// and calculates how many times base is multiplied
// by itself before it surpasses num.
int log(int num, int base) {
	int ans = base;
	int counter = 0;			// counting the number of times we can
								// multiply the base before surpassing
								// starting num.

	while(ans <= num) {
		ans *= base;
		counter ++;
	}
	return counter;				// counter is the exponent
}


// from Eitan:
// The main function should read in two integer values from the user. 
// If either input is negative, the main function should print out 
// "Both inputs must be non-negative" and return. If both inputs are 
// positive, the main function should call log, specifying the first 
// user input as the first argument (i.e. num) and the second user
// input as the second argument (i.e. base). The main function should
// then print the result returned by log before returning.
int main() {
	int base;
	int num;
	std::cout << "Please input a base\n";
	std::cin >> base;
	std::cout << "Please input a starting number\n";
	std::cin >> num;				//getting input from user

	if(base < 1 || num < 1) {		// checking for negatives
		std::cout << "Both inputs must be non-negative\n";
		return 0; 
	}
	std::cout << log(num,base)<<"\n";	// Printing result
	return 0;
}
