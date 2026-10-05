
#include "sha.hpp"
#include <iostream>
#include <cstring>
#include <iostream>


// TODO: add the '-h/--help' option
// TODO: add the '-c/--compare' option
// TODO: improve Options into separate library
// TODO: find other options to implement
int usage(int argc, char *argv[])
{
	std::cout << "Usage: " << argv[0] << " \"example string\"\n";
	// TODO: add '-f/--file' option to hash a specific file
	// std::cout << "Usage: " << argv[0] << " -f [filename]\n"; 
	return (1);
}

int main(int argc, char *argv[])
{
	if (argc > 2)
	{
		return (usage(argc, argv));
	}
	
	sha256(argv[1], std::strlen(argv[1]));

	return 0;
}
