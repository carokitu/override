#include <stdio.h>

char name[256];

int verify_user_pass(char *password) {
	return strcmp(password, "admin");
}

int verify_user_name() {
	puts("verifying username....\n");
	return strncmp(name, "dat_will", 7);
}

int main() {
	int cmp;
	char pass[64];

	bzero(pass, 64);
	
	cmp = 0;
	
	puts("********* ADMIN LOGIN PROMPT *********");	
	printf("Enter Username: ");
	fgets(name, 256, stdin);
	
	cmp = verify_user_name();
	
	if (cmp != 0) {
		puts("nope, incorrect username...\n");
		return 1;
	}

	puts("Enter Password: ");
	fgets(pass, 100, stdin);
	cmp = verify_user_pass(pass);
	if (cmp == 0 || cmp != 0) {
		puts("nope, incorrect password...\n");
		return 1;
	}
	return 0;
}
