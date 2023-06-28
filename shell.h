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

#define MAX_LINE 1024
#define MAX_ARGUMENTS 10
#define MAX_PATH 2048
#define MAX_VAR 100
#define MAX_TOKEN 100

#define MAX_ALIASES 100
#define MAX_ALIAS_NAME 50
#define MAX_ALIAS_VALUE 100
#define BUFFER_SIZE 1024

extern char **environ;

/* Function prototype */

/* main.c */
int main(void);
int argts_handle(int cmds_count, char **cmds,
char **argts, char **env);
int builtin(char **argts);

void bling(void);
/*interp*/
int parse_inputs(char *buff, char **argts);
void cmd_ARGS(char **argts, char **env);
void path_checker(char **argts, char **env);
void executer(char *cmd, char **argts, char **env);
void exec_cmd(char **argts, char **env);

/* builtins.c */
void prints_env(char **environ);
void ext_shell(int status);
void sets_env(char *vars, char *val);
void unsets_env(char *vars);

/* cd_funcs.c */
void cd_runs(char *path);
void cd_hm(void);
void cd_paths(char *path);
void cd_prevs(void);

/* strtok_functions.c */
char *gets_token(char *token, const char *delim, int n);

/* shell_exit.c */
void ext_sh(char **args);

/* get_line.c */
char *get_line(const int fd);

/* shell_1.c */
int str_compare(char *str1, char *str2);
char *str_cate(char *dest, char *src);
char *str_dup(char *str);
int _atoi(char *str);
int str_len(char *str);

/* shell_2.c */
int strn_compare(char *str1, char *str2, int n);
char *get_env(char *name);
char *str_tok(char *str, const char *delim);
char *strn_copy(char *dest, char *src, int n);
char *str_copy(char *dest, const char *src);

/* shell_3.c */
char *strn_cate(char *dest, char *src, int n);
char *strn_tok(char *str, const char *delim, int n);
char *str_chr(char *str, char c);
char *_itoa(int numb);
int parse_argts(char *buff, char **argts);


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

struct AliasData
{
	struct Alias aliases[MAX_ALIASES];
	int numAliases;
};

#endif
