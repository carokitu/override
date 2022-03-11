#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int auth(char *login, int entry)
{
	short size;
	short length;
	unsigned long arg;
	unsigned long arg2;

	login[strcspn(login, "\n")] = 0;
	length = strnlen(login, 32);

	if (length <= 5)
		return 1;

	if (ptrace(0, 1, 0, 0) == -1)
	{
		puts("\033[32m---------------------------.");
		puts("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m---------------------------.");
		return 1;
	}

	arg = ((*(login + 3) ^ 4919) & 6221293);
	arg2 = 0;

	while (arg2 < length)
	{
		if (login[arg2] <= 31)
			return 1;

		arg2 = login[arg2] ^ arg;

		arg = arg2 - (((((arg2 - (arg * 2284010283)) / 2) + (arg * 2284010283)) / 1024) * 1337);
	}
}

int main(int argc, char **argv)
{
	char login[32];
	int entry;

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");

	printf("-> Enter Login: ");
	fgets(login, 32, stdin);

	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");

	scanf("%u", &entry);

	if (!auth(login, entry))
	{
		puts("Authenticated!");
		system("/bin/sh");
		return (0);
	}

	return (1);
	return __stack_chk_fail();
}
