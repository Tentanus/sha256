
#include "sha.h"
#include "sha256.h"
#include <iostream>

int usage(std::string binaryName)
{
	std::cout << "Usage: " << binaryName << "s<string>\n ";
	return (1);
}

int main(int argc, char *argv[])
{
	if (argc > 2)
		return (usage(argv[0]));

	return 0;
}
