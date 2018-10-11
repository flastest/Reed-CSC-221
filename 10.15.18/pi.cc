#include <iostream> 
#include <cmath>


double gridpi(unsigned npoints) {
	const double size = npoints;			// idk did u want to also do 1/4 of npoints??
	double inCircle = 0;					// init counter for num of things in circle
	double inSquare = size*size; 			// number of total darts thrown in this part of square

	double posX;							// inits pos of current dart
	double posY;

	for (double i = 0; i < size; i++) {		// iterates thru rows
		posY = double(i/size);				// setting posY for this row
		for (double j = 0; j < size; j++) {	// iterates thru each pt
			posX = j/size;					// setting posX for this position
			if(std::hypot(posX,posY) < 1.0) {
				inCircle++;
			}
		}
	}
	return (inCircle/inSquare)*4.0;
}

int main()	{
	std::cout << "for a trial of 10, pi is:\n";
	std::cout << gridpi(10) << "\n";
	
	std::cout << "for a trial of 100, pi is:\n";
	std::cout << gridpi(100) << "\n";
	
	std::cout << "for a trial of 1000, pi is:\n";
	std::cout << gridpi(1000) << "\n";
	
	std::cout << "for a trial of 10000, pi is:\n";
	std::cout << gridpi(10000) << "\n";
	


	return 0;
}