#include <stdio.h>
#include <stdlib.h>

int main () {
	int entry;

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");

	printf("Password:");
	if (scanf("%d", &entry) == 5276) {
		puts("\nAuthenticated!");
		system("/bin/sh");
		return 0;
	}
	puts("\nInvalid Password!");
	return 1;
}
