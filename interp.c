#include "shell.h"

/**
 * parse_inputs - parses the input from the user
 * @buff: buffer to store the input
 * @cmds: array of commands
 * Return: number of commands
 */
int parse_inputs(char *buff, char **cmds)
{
int i = 0;
int t = 0;
char *token;

token = strtok(buff, ";");
while (token != NULL)
{
cmds[i] = malloc(sizeof(char) * MAX_LINE);
if (cmds[i] == NULL)
{
perror("Error");
for (t = 0; t < i; t++)
free(cmds[t]);
return (0);
}
strn_copy(cmds[i], token, MAX_LINE);
cmds[i][MAX_LINE - 1] = '\0';
token = strtok(NULL, ";");
i++;
}
cmds[i] = NULL;
return (i);
}

/**
 * cmd_ARGS - runs if the command is an absolute or relative path
 * @argts: array of arguments
 * @env: environment variables
 * Return: void
 */
void cmd_ARGS(char **argts, char **env)
{
pid_t pid;

/* Fork a child process */
pid = fork();
if (pid == 0)
{
/* Child process */
if (execve(argts[0], argts, env) == -1)
{
perror("Error");
}
}
else if (pid < 0)
{
/* Error forking */
perror("Error");
}
else
{
/* Parent process */
waitpid(pid, NULL, 0);
}
}

/**
 * path_checker - checks if the command is in the PATH
 * checks in PATH
 * @argts: array of arguments
 * @env: environment variables
 * Return: void
 */
void path_checker(char **argts, char **env)
{
char *path, *token;
char *cmd = NULL;
char *path_arr[MAX_PATH];
struct stat tr;
int i = 0;
int t = 0;

path = get_env("PATH");
token = strtok(path, ":");
while (token != NULL)
{path_arr[i] = malloc(sizeof(char) * MAX_PATH);
if (path_arr[i] == NULL)
{
perror("Error");
for (t = 0; t < i; t++)
free(path_arr[t]);
return;
}
strn_copy(path_arr[i], token, MAX_PATH);
path_arr[i][MAX_PATH - 1] = '\0';
cmd = strn_cate(path_arr[i], "/", 1);
cmd = strn_cate(cmd, argts[0], str_len(argts[0]));
if (stat(cmd, &tr) == 0)
{
executer(cmd, argts, env);
for (t = 0; t <= i; t++)
free(path_arr[t]);
return;
}
token = strtok(NULL, ":");
i++;
}
perror("Error");
for (t = 0; t <= i; t++)
free(path_arr[t]);
return;
}

/**
 * executer - executes the command with the arguments
 * @cmd: command to execute
 * @argts: array of arguments
 * @env: environment variables
 * Return: void
 */
void executer(char *cmd, char **argts, char **env)
{
pid_t pid;

pid = fork();
if (pid == 0)
{
if (execve(cmd, argts, env) == -1)
{
perror("Error");
}
}
else if (pid < 0)
{
perror("Error");
}
else
{
waitpid(pid, NULL, 0);
}
}

/**
 * exec_cmd - executes the command with the arguments
 * checks in PATH
 * @argts: array of arguments
 * @env: environment variables
 * Return: void
 */
void exec_cmd(char **argts, char **env)
{
if (argts[0] == NULL)
return;
if (str_compare(argts[0], "exit") == 0)
{
ext_sh(argts);
}
if (str_compare(argts[0], "env") == 0)
{
prints_env(env);
return;
}
if (str_compare(argts[0], "setenv") == 0)
{
sets_env(argts[1], argts[2]);
return;
}
if (str_compare(argts[0], "unsetenv") == 0)
{
unsets_env(argts[1]);
return;
}
if (str_compare(argts[0], "cd") == 0 && argts[1] == NULL)
{
cd_hm();
return;
}
if (str_compare(argts[0], "cd") == 0 && argts[1] != NULL)
{
cd_runs(argts[1]);
return;
}
if (argts[0][0] == '/' || argts[0][0] == '.')
{
cmd_ARGS(argts, env);
}
else
{
path_checker(argts, env);
}
}
