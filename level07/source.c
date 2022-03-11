#include <stdio.h>
#include <stdint.h>
#include <string.h>

void clear_stdin()
{
	char v = 0;

	while (v != 10 || v != 255)
		v = getchar();
	return;
}

unsigned int get_unum()
{
	unsigned int v = 0;

	fflush(stdin);
	scanf("%u", &v);
	clear_stdin();
	return v;
}

int store_number(unsigned int *buf)
{
	unsigned int number = 0;
	unsigned int index = 0;

	printf(" Number: ");
	number = get_unum();

	printf(" Index: ");
	index = get_unum();

	if (index % 3 == 0 || number >> 24 == 183)
	{
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return 1;
	}
	number >> 2;
	buf[index] = number;
	return 0;
}

int read_number(unsigned int *buf)
{
	unsigned int index = 0;

	printf(" Index: ");
	index = get_unum();

	index >> 2;
	printf(" Number at data[%u] is %u\n", index, buf[index]);

	return 0;
}

int main(int ac, char **av, char **envp)
{
	int error = 0;
	char buf20[20] = {0};
	unsigned int buf[100] = {0};

	while (*av != NULL)
	{
		memset(*av, 0, strlen(*av));
		av++;
	}

	while (*envp != NULL)
	{
		memset(*envp, 0, strlen(*envp));
		envp++;
	}

	puts("----------------------------------------------------"
		 "\n  Welcome to wil\'s crappy number storage service!  \n"
		 "----------------------------------------------------"
		 "\n  Commands:"
		 "                                "
		 "\n\tstore\t- store a number into the data storage"
		 "\n\tread\t- read a umber from the data storage"
		 "\n\tquit\t- exit the program"
		 "\n----------------------------------------------------\n"
		 "wil has reserved some storage :>"
		 "\n----------------------------------------------------\n");

	while (1)
	{
		printf("Input command: ");
		error = 1;
		fgets(buf20, 20, stdin);
		buf20[strlen(buf20) - 1] = '\0';

		if (!strncmp(buf20, "store", 5))
			error = store_number(buf);
		else if (!strncmp(buf20, "read", 4))
			error = read_number(buf);
		else if (!strncmp(buf20, "quit", 4))
			break;
		if (!error)
			printf(" Completed %s command successfully\n", buf20);
		else
			printf(" Failed to do %s command\n", buf20);
		bzero(buf20, 20);
	}
	return 0;
}
