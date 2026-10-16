#ifndef SHA_H
#define SHA_H

#include <stdint.h>
#include <string>

// Personal Includes

	const std::string hash(const char *str, uint64_t size);

//  -=- DEFINES -=-
#define FAILURE 1
#define SUCCESS 0


#endif // !SHA_H
