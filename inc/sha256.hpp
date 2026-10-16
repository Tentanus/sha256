#ifndef SHA256_H
#define SHA256_H

// Personal Includes
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstdint>

// Personal Includes
#include "MessageBlock.hpp"

// TODO: concidere changing it to a namespace since there
// -     is no instance needed of this sha256 object.
namespace sha256
{
	const std::string hash(const char *str, uint64_t size);
};

//  -=- DEFINES -=-

// SHA256 definitions
#define SHA256_MESSAGE_SIZE 512		// bits     64 bytes long
#define SHA256_SCHEDULE_SIZE 64		// Word blocks in schedule

// Operations (32 bits)
#define ROTR(x, n) ((x >> (n & 31)) | (x << ((32 - (n & 31)) & 31)))

// Logical functions (32 bits)
#define Ch(x, y, z) ((x & y) ^ (~x & z))
#define Maj(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define BSIG0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define BSIG1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SSIG0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3))
#define SSIG1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10))

#endif // !SHA256_H
