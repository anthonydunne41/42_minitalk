#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	pid_t pid = atoi(argv[1]);
	// int command = atoi(argv[2]);

	while (1)
	{
		kill(pid, SIGUSR1);
		kill(pid, SIGUSR2);
		sleep(1);
	}

	sleep(5);
	kill(pid, SIGKILL);
}
