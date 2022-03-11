#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

void log_wrapper(FILE *file, char *context, char *arg)
{
    char cpy[254];

    strcpy(cpy, context);
    snprintf(cpy + strlen(cpy), 254 - strlen(cpy), arg);
    cpy[strcspn(cpy, "\n")] = '\0';
    fprintf(file, "LOG: %s\n", cpy);
}

int main(int argc, char **argv)
{
    char buf[104];
    int8_t c = 255;
    int value = -1;
    FILE *file;
    FILE *file_2;

    if (argc != 2)
        printf("Usage: %s filename\n", argv[0]);

    file = fopen("./backups/.log", "w");

    if (!file)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }

    log_wrapper(file, "Starting back up: ", argv[1]);
    file_2 = fopen(argv[1], "r");

    if (!file_2)
    {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }

    memcpy(buf, "./backups/", 10);
    strncat(buf, argv[1], 99);
    value = open(buf, 193, 432);

    if (value < 0)
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }

    while (1)
    {
        write(value, c, 1);
        c = fgetc(file_2);
        if (c != 255)
            break;
    }

    log_wrapper(file, "Finished back up ", argv[1]);
    fclose(file_2);
    close(value);
    return 0;
}