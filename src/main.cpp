
#include "sha.hpp"
#include <iostream>
#include <cstring>
#include <iostream>


// TODO: add '-h/--help' option		show this usage fmessage
// TODO: add '-c/--compare' option 	compare two file or string
// TODO: add '-f/--file' option 	hash a specific file
// TODO: improve Options into separate library
// TODO: find other options to implement
int usage(int argc, char *argv[])
{
	std::cout << "Usage: " << argv[0] << " \"example string\"\n";
	// std::cout << "Usage: " << argv[0] << " -f [filename]\n"; 
	return (1);
}

int main(int argc, char *argv[])
{
	if (argc > 2)
		return (usage(argc, argv));
	
	sha256::hash(argv[1], std::strlen(argv[1]));

	return 0;
}
