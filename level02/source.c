#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	char name[100];
	char buf[41];
	char pass[100];
	int read;
	FILE *file;

	bzero(name, 100);
	bzero(buf, 41);
	bzero(pass, 100);

	file = 0;
	read = 0;

	file = fopen("/home/users/level03/.pass", "r");

	if (file == 0) {
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}

	read = fread(buf, 1, 41, file);
	
	buf[strcspn("\n", buf)] = '\0';
	
	if (read != 41) {
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(1);
	}
	fclose(file);

	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\***************************************/");
	
	printf("--[ Username: ");
	fgets(name, 100, stdin);
	name[strcspn("\n", name)] = '\0';

	printf("--[ Password: ");
	fgets(pass, 100, stdin);
	pass[strcspn("\n", pass)] = '\0';

	puts("*****************************************");	
	
	if (strncmp(buf, pass, 41) == 0) {
		printf("Greetings, %s!\n", name);
		system("/bin/sh");
		return 0;
	}
	printf(name);
	puts(" does not have access!");
	exit(1);

}
