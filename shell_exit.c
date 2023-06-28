#include "shell.h"

/**
 * ext_sh - exits the shell
 * @args: array of arguments
 * Return: exit status
 */
void ext_sh(char **args)
{
int status = 0;

if (args[1] != NULL)
{
status = _atoi(args[1]);
}
exit(status);
}



/**
 * parse_argts - parses the arguments from the user
 * @buff: buffer to store the input
 * @argts: array of arguments
 * Return: number of arguments
 */
int parse_argts(char *buff, char **argts)
{
int i = 0;
char *token;

token = strtok(buff, " \t\n");
while (token != NULL)
{
argts[i] = malloc(sizeof(char) * MAX_LINE);
if (argts[i] == NULL)
{
perror("Error");
for (i = 0; argts[i] != NULL; i++)
free(argts[i]);
return (0);
}
strn_copy(argts[i], token, MAX_LINE);
token = strtok(NULL, " ");
i++;
}
argts[i] = NULL;
return (i);
}
