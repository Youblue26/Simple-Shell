#include "shell.h"

/**
 * main - entry point
 * Return: 0 if successfull
 */
int main(void)
{
char buff[MAX_LINE];
char *argts[MAX_ARGUMENTS];
char *cmds[MAX_ARGUMENTS];
int status = 1;
int  i, num_cmds = 0;
ssize_t bytes_read = 0;


while (status)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
bytes_read = read(STDIN_FILENO, buff, MAX_LINE);
if (bytes_read == 0)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
exit(0);
}
if (bytes_read == -1)
{
perror("Error");
exit(1);
}
buff[bytes_read - 1] = '\0';
num_cmds = parse_inputs(buff, cmds);
argts_handle(num_cmds, cmds, argts, environ);
for (i = 0; i < num_cmds; i++)
free(cmds[i]);
}
return (0);
}

/**
 * argts_handle - handles arguments
 * @cmds_count: number of commands
 * @cmds: commands
 * @argts: arguments
 * @env: environment variables
 * Return: 0 if successful
 */
int argts_handle(int cmds_count, char **cmds,
char **argts, char **env)
{
int i, t, num_argts = 0;

for (i = 0; i < cmds_count; i++)
{
num_argts = parse_argts(cmds[i], argts);
if (num_argts == 0)
{
for (t = 0; argts[t] != NULL; t++)
free(argts[t]);
continue;
}
if (builtin(argts) == 1)
{
for (t = 0; argts[t] != NULL; t++)
free(argts[t]);
continue;
}
if (access(argts[0], F_OK) == 0)
cmd_ARGS(argts, env);
else
path_checker(argts, env);
for (t = 0; argts[t] != NULL; t++)
free(argts[t]);
}
return (0);
}

/**
 * builtin - checks for builtins
 * @argts: arguments
 * Return: 1 if builtin, 0 if not
 */
int builtin(char **argts)
{
if (str_compare(argts[0], "exit") == 0)
ext_sh(argts);
if (str_compare(argts[0], "env") == 0)
prints_env(argts);
if (str_compare(argts[0], "setenv") == 0)
sets_env(argts[1], argts[2]);
if (str_compare(argts[0], "unsetenv") == 0)
unsets_env(argts[1]);
if (str_compare(argts[0], "cd") == 0)
{
if (argts[1] == NULL)
cd_hm();
else if (str_compare(argts[1], "-") == 0)
cd_prevs();

cd_runs(argts[1]);
}
if (str_compare(argts[0], "help") == 0)
{
return (1);
}
return (0);
}
