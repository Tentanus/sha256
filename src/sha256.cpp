#include <cstdint>
#include <stdio.h>

#include "sha256.hpp"

char *sha256(const char *str, uint64_t size)
{
    preprocessor(str, size);

}