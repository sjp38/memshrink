#include <err.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *mem;
size_t sz_mem;

void sighandler(int signo)
{
	switch (signo) {
	case SIGUSR1:
		memset(mem, 1, sz_mem);
		break;
	case SIGINT:
		free(mem);
		exit(0);
		break;
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		errx(1, "Usage: %s <size of memory to alloc/fault>", argv[0]);

	sz_mem = (size_t)atoll(argv[1]);
	mem = malloc(sz_mem);
	memset(mem, 1, sz_mem);

	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);
	while (1)
		sleep(1);

	printf("goodbye\n");
	return 0;
}
