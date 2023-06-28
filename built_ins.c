#include "shell.h"

/**
 * prints_env - prints the environment
 * @environ: environment variables
 * Return: void
 */
void prints_env(char **environ)
{
int i = 0;

while (environ[i] != NULL)
{
write(STDOUT_FILENO, environ[i], str_len(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
}

/**
 * ext_shell - exits the shell with the given status
 * @status: exit status
 * Return: void
 */
void ext_shell(int status)
{
exit(status);
}

/**
 * sets_env - sets the environment variable
 * @vars: variable name
 * @val: variable value
 * Return: void
 */
void sets_env(char *vars, char *val)
{
char *new = NULL;
int i = 0;
int t = 0;
int r = 0;
int length = 0;

while (environ[i] != NULL)
{
if (strn_compare(environ[i], vars, str_len(vars)) == 0)
{
length = str_len(environ[i]) + str_len(val) + 1;
new = malloc(sizeof(char) * length);
if (new == NULL)
{
perror("Error: ");
free(new);
return;
}
while (environ[i][t] != '\0')
{
new[t] = environ[i][t];
t++;
}
new[t] = '=';
t++;
while (val[r] != '\0')
{
new[t] = val[r];
t++;
r++;
}
new[t] = '\0';
environ[i] = new;
return;
}
i++;
}
free(new);
}

/**
 * unsets_env - unsets the environment variable
 * @vars: variable name
* Return: void
 */
void unsets_env(char *vars)
{
int i = 0;
int t = 0;
int r = 0;
int length = 0;
char *new;

while (environ[i] != NULL)
{
if (strn_compare(environ[i], vars, str_len(vars)) == 0)
{
length = str_len(environ[i]);
new = malloc(sizeof(char) * length);
if (new == NULL)
{
perror("Error: ");
return;
}
while (environ[i][t] != '\0')
{
if (environ[i][t] == '=')
{
t++;
break;
}
new[t] = environ[i][t];
t++;
}
while (environ[i][t] != '\0')
{
new[r] = environ[i][t];
t++;
r++;
}
new[r] = '\0';
environ[i] = new;
return;
}
i++;
}
}
