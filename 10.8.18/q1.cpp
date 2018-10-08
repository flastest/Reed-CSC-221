#include <iostream>

int main() {
	int firstNumber;
	int secondNumber;
	int thirdNumber;
	std::cout << "Enter three integers\n";
	std::cin >> firstNumber >> secondNumber >> thirdNumber;

	int smallestNum= firstNumber;

	if(smallestNum > secondNumber) {
		smallestNum = secondNumber;
	}
	if (smallestNum > thirdNumber) {
		smallestNum = thirdNumber;
	}

	std::cout << "The smallest number is ";
	std::cout << smallestNum;
	return 0;
}