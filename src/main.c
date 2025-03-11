
#include "sha.h"
#include "sha256.h"

int usage(char *binary_name)
{
	ft_printf("Usage: %s <string>\n", binary_name);
	return (1);
}

int main(int argc, char *argv[])
{
	(void)argc;

	if (argc != 2)
		usage(argv[0]);

	sha256(argv[1]);

	return 0;
}
