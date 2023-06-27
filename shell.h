#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>


#define MAX_COMMAND_LENGTH 1000
#define MAX_LINE 1024
#define MAX_ARGUMENTS 100
#define MAX_PATH 2048
#define MAX_VAR 100
#define MAX_TOKEN 100

#define MAX_ALIASES 100
#define MAX_ALIAS_NAME 50
#define MAX_ALIAS_VALUE 100
#define BUFFER_SIZE 1024

/*getenvs.c*/
void print_error(const char *message);
int main(int argc, char *argv[]);
char success_message[128];

/*cd.c*/
void change_directory(char *directory);
int main(int argc, char *argv[]);

/*commands_separator.c*/
void run_command(const char *command);
void run_commands(const char *commands);

/*logical_operators.c*/
int execute_command(const char *command);
void parse_commands(char *commands);

/*alias.c*/
struct AliasData;
void process_alias_command(struct AliasData *data, int argc, char *argv[]);
void set_alias(struct AliasData *data, const char *name, const char *value);
void print_alias(const struct AliasData *data, const char *name);
void print_aliases(const struct AliasData *data);

/**
 * struct Alias - Represents an alias with its name and value
 * @name: The name of the alias
 * @value: The value of the alias
 */

struct Alias 
{
char name[MAX_ALIAS_NAME];
char value[MAX_ALIAS_VALUE];
};

/**
 * struct AliasData - Represents the data related to aliases
 * @aliases: An array of Alias structures representing aliases
 * @numAliases: The number of aliases currently defined
 */

struct AliasData {
struct Alias aliases[MAX_ALIASES];
int numAliases;
};

/*var.c*/
void handle_variables(char* cmd);



/*file_input.c*/
int main(int argc, char *argv[]);
void run_commands_from_file(const char* filename);
#endif
