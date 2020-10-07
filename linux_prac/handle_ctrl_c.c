#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_sigint(int signum) {
	printf("Catch ID: %d\n", signum);
	exit(signum);
}

int main (int argc, char** argv[]) {
	signal(SIGINT, handle_sigint);
	while (1) {
		printf("Program processing...\n");
		sleep(1);
	}
	return EXIT_SUCCESS;
}
