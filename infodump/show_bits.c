#include <stdio.h>
#include "sha256.hpp"

void printBits(uint32_t *bits, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			printf("%d", (bits[i] >> (32 - j - 1)) & 1);
		}
		printf(" ");
	}
}

int main(int argc, char **argv)
{
	uint32_t bits[] = {
		0x00000000,			// 0
		0x00000001,			// 1
		0x40000000,			// 1073741824
		0x80000000,			// -2147483648 
		0x7FFFFFFF,			// 2147483647
		0xAAAAAAAA,			// -1431655766
		0xFFFFFFFF,
	};
	for (int i = 0; bits[i] != 0xFFFFFFFF; i++)
	{
		printf("bits[%d]\t", i);
		printBits(&bits[i], 1);
		printf("\t%d\n\t", bits[i]);
		uint32_t bits2 = ROTR(bits[i], 1);
		printBits(&bits2, 1);
		printf("\t%d\n\n", bits2);
	}
	return 0;
}