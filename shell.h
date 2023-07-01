#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_LINE 1024
#define MAX_ARGUMENTS 10
/*#define MAX_PATH 2048*/
#define MAX_VAR 100
#define MAX_TOKEN 100

/* Function prototype */

/* main.c */
int main(int ac, char **av, char **env );
void bling(char **av, char **env);
#endif
