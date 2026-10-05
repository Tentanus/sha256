#include "sha256.hpp"
#include <stdio.h>
#include <stdint.h>
#include <iostream>

void printBits(int16_t *bits, int arrayLength)
{
	int dataSize = sizeof(typeof(bits[0])) * 4;

	for (int i = 0; i < arrayLength; i++)
	{
		std::cout << "\n\t";
		for (int j = 0; j < dataSize; j++)
		{
			printf("%d", (bits[i] >> (dataSize - j - 1)) & 1);
		}
	}
	std::cout << std::endl;
}

void showCh(int16_t x, int16_t y, int16_t z)
{
	std::cout << "\n\nshow Choice";
	int16_t invx = ~x;
	int16_t Choice = Ch(x, y, y);
	
	printBits(&x, 1);
	printBits(&y, 1); std::cout << " &\n";
	std::cout << "----------------------------------";
	int16_t A = (x & y);
	printBits(&A, 1);
	std::cout << "\n\n";

	
	printBits(&invx, 1);
	printBits(&y, 1); std::cout << " &\n";
	std::cout << "----------------------------------";
	int16_t B = (~x & z);
	printBits(&B, 1);
	std::cout << "\n\n";

	printBits(&A, 1);
	printBits(&B, 1);
	std::cout << "\n----------------------------------";
	printBits(&Choice, 1);
	std::cout << "\n";
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	#define ARR_SIZE 4
	int16_t bits[ARR_SIZE] = {
							static_cast<int16_t>(0x8F),
							static_cast<int16_t>(0x55),
							static_cast<int16_t>(0xAA),
							static_cast<int16_t>(0x00),
							};
	
	// std::cout << "bits[" << i << "]\tsize: " << sizeof(typeof(bits[i])) << " bytes\n";
	printBits(bits, ARR_SIZE);
	// std::cout << "\n";

	// printBits(&bits[i], 1);

	// showCh(bits[0], bits[1], bits[2]);
	int16_t res = Ch(bits[0], bits[1], bits[2]);
	std::cout << "result: ";
	printBits(&res, 1);

	std::cout << std::endl;


	return 0;
}
