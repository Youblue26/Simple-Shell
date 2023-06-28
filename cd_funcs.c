#include "shell.h"

/**
 * cd_hm - changes directory to home
 * Return: void
 */
void cd_hm(void)
{
char *home = get_env("HOME");
char *pwd = get_env("PWD");
char *newpwd;

if (chdir(home) == -1)
{
perror("hsh");
}
else
{
newpwd = malloc(str_len(home) + 6);
strn_copy(newpwd, "PWD=", 4);
strn_cate(newpwd, home, str_len(home) + 1);
sets_env("PWD", home);
sets_env("OLDPWD", pwd);
free(newpwd);
}
}
/**
 * cd_paths - changes directory to path
 * @path: arguments
 * Return: void
 */

void cd_paths(char *path)
{
char *token;

token = str_tok(path, " ");
while (token != NULL)
{
path = malloc(str_len(token) + 1);
strn_copy(path, token, str_len(token) + 1);
token = strtok(NULL, " ");
}
if (chdir(path) == -1)
{
perror("hsh");
}
else
{
sets_env("OLDPWD", get_env("PWD"));
}
}

/**
 * cd_prevs - changes directory to previous
 * Return: void
 */
void cd_prevs(void)
{
char *prevpwd = get_env("OLDPWD");
int ret;

if (prevpwd == NULL)
{
write(STDERR_FILENO, "hsh: cd: OLDPWD not set\n", 24);
return;
}
ret = chdir(prevpwd);
if (ret == -1)
{
perror("hsh");
}
else
{
sets_env("OLDPWD", get_env("PWD"));
sets_env("PWD", prevpwd);
}
}

/**
 * cd_runs - runs the cd command
 * @path: arguments
 * Return: void
 */
void cd_runs(char *path)
{
if (strn_compare(path, "~", 1) == 0 || str_compare(path, "--") == 0)
{
cd_hm();
}
if (strn_compare(path, "-", 1) == 0)
{
cd_prevs();
}
else
{
cd_paths(path);
}
}
