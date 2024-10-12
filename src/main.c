
#include <sha256.h>
#include <sha256_dev.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return 1;
	}

	sha256(argv[1]);

	return 0;
}
