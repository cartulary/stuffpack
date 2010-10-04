#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>

void catch_alarm(const int sig);
pid_t shell;

int main(int argc, char* argv[])
{
	signal(SIGALRM, catch_alarm);

	shell = fork();
	if (shell == 0)
	{
		int result = execl("/bin/sh",NULL);
		if (result == -1)
		{
			printf("failure with errno = %s [%d] \n",strerror(errno),errno);
		}
	}
	else
	{
	//	unsigned int sessionTime = 5*60;
		unsigned  sessionTime = 2;
		if (argc > 1)
		{
			sessionTime = (int)(argv[1], NULL,10);
		}
		alarm(sessionTime);
		int status;
		waitpid(shell, &status,0);
		printf("session timed out\n");
	}
	return 0;
}

void catch_alarm(const int sig)
{
	if (sig == SIGALRM)
	{
		printf("Session timeout");
		kill(shell,SIGKILL);
	}
}

