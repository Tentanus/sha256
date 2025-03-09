
#include "sha.h"

uint32_t rotl(uint32_t x, uint32_t n)
{
	return ((x << n) | (x >> (32 - n)));
}

uint32_t rotr(uint32_t x, uint32_t n)
{
	return ((x >> n) | (x << (32 - n)));
}
