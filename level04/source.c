#include <unistd.h>
#include <strings.h>
#include <sys/prctl.h>

int main()
{
	char buf[128];
	pid_t pid;
	long ptrace_value;
	long wait_value;
	int compare;
	int compare_2;

	pid = fork();
	bzero(buf, 128);

	ptrace_value = 0;
	wait_value = 0;
	if (pid == 0)
	{
		prctl(1, 1);
		ptrace(0, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buf);
	}
	else
	{
		while (1)
		{
			wait(&wait_value);
			compare = wait_value;
			if (compare & 127)
			{
				compare_2 = wait_value;
				if (((compare_2 & 127) + 1) >> 1 > 0)
				{
					puts("child is exiting...");
					break;
				}
			}
			ptrace_value = ptrace(3, pid, 44, 0);

			if (ptrace_value == 11)
			{
				puts("no exec() for you");
				kill(wait_value, 9);
				break;
			}
		}
	}
	return(0);
}
