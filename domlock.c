#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
	struct rlimit lim;
	size_t sz_mem;
	void *mem;
	char tmp;

	if (argc < 2)
		errx(1, "Usage: %s <size of memory to lock>", argv[0]);

	sz_mem = (size_t)atoll(argv[1]);
	lim.rlim_cur = sz_mem;
	lim.rlim_max = sz_mem;
	if (setrlimit(RLIMIT_MEMLOCK, &lim))
		err(1, "setrlimit() failed");
	mem = malloc(sz_mem);
	memset(mem, 0, sz_mem);
	mlock(mem, sz_mem);

	printf("Enter any character to exit\n");
	if (scanf("%c", &tmp) == 0)
		err(1, "scanf returned 0");
	free(mem);

	return 0;
}
