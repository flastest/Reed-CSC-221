#include <iostream>
#include <string>

// big is the number which you are looking for
// multiples of small.
bool isMultiple(int small, int big) {
	bool result = false;
	if(big % small == 0) {
		result = true;
	}
	return result;
}


// Stolen from Eitan:
// The main function should use a loop to read in 10 integers 
// from the user using cin. For each number read in, the loop 
// iteration should call the isMultiple function to determine
// if the number just read in from the user is a multiple of
// the value stored in num. The main function should then
// print out to standard output using cout how many of the 10
// numbers were multiples of num.
int main() {
	int num;
	std::cout << "Give me a number you want to find multiples of.\n";
	std::cin >> num;
	std::cout << "Thanks\n";

	int counter = 0; // initializing counter of multiples of num

	for (int i = 0; i < 10; ++i)
	{
		int input;								// Input is the input from the user.
		std::cout << "Enter a number to see if it is a multiple of " << num << "\n";
		std::cin >> input;

		std::string output = " is not a multiple of "; 	// This is default what will return if
									 				// the number is not a multiple, it will
													// change if isMultiple return true
		if (isMultiple(input,num)) {
			output = " is a multiple of ";
			counter++;
		}

		std::cout << input << output << num << "\n"; // Printing a gramatically correct sentence

	}
	std::cout << "There were " << counter << " multiples of " << num;
	return 0;
}