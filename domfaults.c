#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	size_t sz_mem;
	void *mem;
	char tmp;

	if (argc < 2)
		errx(1, "Usage: %s <size of memory to alloc/fault>", argv[0]);

	sz_mem = (size_t)atoll(argv[1]);
	mem = malloc(sz_mem);
	memset(mem, 1, sz_mem);

	printf("Enter any character to exit\n");
	if (scanf("%c", &tmp) == 0)
		err(1, "scanf returned 0");
	free(mem);

	return 0;
}
