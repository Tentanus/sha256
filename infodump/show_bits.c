#include "sha256.hpp"
#include <stdio.h>
#include <stdint.h>
#include <iostream>

void printBits(int32_t *bits, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			printf("%d", (bits[i] >> (32 - j - 1)) & 1);
		}
		printf("\n\t\t");
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	#define ARR_SIZE 7
	int32_t bits[ARR_SIZE] = {	static_cast<int32_t>(0x00000000), // 0
							   	static_cast<int32_t>(0x00000001), // 1
							   	static_cast<int32_t>(0x40000000), // 1073741824
							   	static_cast<int32_t>(0x80000000), // -2147483648
							   	static_cast<int32_t>(0x7FFFFFFF), // 2147483647
							   	static_cast<int32_t>(0xAAAAAAAA), // -1431655766
							   	static_cast<int32_t>(0xFFFFFFFF)  // -1
								};

	for (int i = 0; i < ARR_SIZE; i++)
	{
		printf("bits[%d]\t\t", i);
		printBits(&bits[i], 1);
		printf("\t%d\n  ROTL(1):\t", bits[i]);\
		int32_t arr[3] = {	ROTL(bits[i], 1), 
							(bits[i] << 1), 
							(bits[i] >> (sizeof(bits[i]) * 8 - 1))
						};
		printBits(arr, 3);
		printf("\t%d\n", arr[1]);
	}


	return 0;
}
