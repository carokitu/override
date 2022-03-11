#include <stdio.h>

void		clear_stdin()
{
	char	v = 0;

	while (v != 0xff)
	{
		v = getchar();
		if (v == '\n')
			return;
	}
}

unsigned int	get_unum()
{
	unsigned int	unum = 0;

	fflush(stdout);
	scanf("%u", unum);
	clear_stdin();

	return unum;
}

void		decrypt(int arg1)
{
	size_t len ;
	char test[17] = "Q}|u`sfg~sf{}|a3";
	int i = 0;

	len = strlen(test);
	for (i = 0; i < len; i++)
	{
		test[i] = test[i] ^ arg1;
	}
	if (strncmp(test, "Congratulations!", 17) == 0)
		system("/bin/sh");
	else
		puts("\nInvalid Password");
	return;
}

void		test(int value, int number)
{
	int tmp;

	tmp = number - value;

	switch (tmp)
	{
		case 0x1:
			decrypt(tmp);
			break;
		case 0x2:
			decrypt(tmp);
			break;
		case 0x3:
			decrypt(tmp);
			break;
		case 0x4:
			decrypt(tmp);
			break;
		case 0x5:
			decrypt(tmp);
			break;
		case 0x6:
			decrypt(tmp);
			break;
		case 0x7:
			decrypt(tmp);
			break;
		case 0x8:
			decrypt(tmp);
			break;
		case 0x9:
			decrypt(tmp);
			break;
		case 0x10:
			decrypt(tmp);
			break;
		case 0x11:
			decrypt(tmp);
			break;
		case 0x12:
			decrypt(tmp);
			break;
		case 0x13:
			decrypt(tmp);
			break;
		case 0x14:
			decrypt(tmp);
			break;
		case 0x15:
			decrypt(tmp);
			break;
		default:
			decrypt(rand());
			break;
	}
	return;
}

int	main(int c, char **argv)
{
	int	value;

	srand(time(0));

	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");

	scanf("%d", value);
	test(value, 322424845);

	return 0;
}
