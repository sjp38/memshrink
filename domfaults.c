#include <err.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *mem;

void sighandler(int signo)
{
	free(mem);
	printf("bye\n");
	signal(SIGINT, SIG_DFL);
}

int main(int argc, char *argv[])
{
	size_t sz_mem;

	if (argc < 2)
		errx(1, "Usage: %s <size of memory to alloc/fault>", argv[0]);

	sz_mem = (size_t)atoll(argv[1]);
	mem = malloc(sz_mem);
	memset(mem, 1, sz_mem);

	signal(SIGINT, sighandler);
	while (1)
		sleep(1);

	printf("goodbye\n");
	return 0;
}
