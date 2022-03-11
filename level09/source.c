#include <stdio.h>
#include <string.h>
#include <strings.h>

struct t_infos
{
    char message[180];
    char username[128];
    int value;
} t_infos;

void secret_backdoor() {
    char buf[128];

    fgets(buf, 128, stdin);
    system(buf);
}

void set_msg(struct t_infos *infos)
{
    char message[1024];

    bzero(message, 1024);
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(message, 1024, stdin);
    strncpy(infos->message, message, infos->value);
}

void set_username(struct t_infos *infos)
{
    char name[128];
    int value;

    bzero(name, 128);
    puts(">: Enter your username");
    printf(">>: ");
    fgets(name, 128, stdin);

    for (value = 0; value < 40 && name[value]; value++)
        infos->username[value] = name[value];

    printf(">: Welcome, %s", infos->username);
}

void handle_msg(void)
{
    struct t_infos infos;

    bzero(infos.message + 140, 40);
    infos.value = 140;
    set_username(&infos);
    set_msg(&infos);
    puts(">: Msg sent!");
}

int main()
{
    puts("--------------------------------------------"
         "\n|   ~Welcome to l33t-m$n ~    v1337        |"
         "\n--------------------------------------------");
    handle_msg();
    return 0;
}