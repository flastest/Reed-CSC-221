#include <iostream>

int main() {
	int firstNumber;
	int secondNumber;
	int thirdNumber;
	std::cout << "Enter three integers\n";
	std::cin >> firstNumber >> secondNumber >> thirdNumber;

	int biggestNum= firstNumber;

	if(biggestNum < secondNumber) {
		biggestNum = secondNumber;
	}
	if (biggestNum < thirdNumber) {
		biggestNum = thirdNumber;
	}

	std::cout << "The biggest number is ";
	std::cout << biggestNum;
	return 0;
}