#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t child_pid;
	pid_t wait_result;
	int stat_loc;

	child_pid = fork();
	if (child_pid == 0)
	{
		sleep (1); //Sleep for one second
		printf("Child process - Current PID: %d and Child PID: %d\n", getpid(), child_pid);
	}
	else
	{
		wait_result = waitpid(child_pid, &stat_loc, WUNTRACED);
		printf("Parent process - Current PID: %d and Child PID: %d\n", getpid(), child_pid);
	}
	return (0);
}