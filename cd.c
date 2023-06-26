#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void change_directory(char *directory)
{
char *new_dir;

if (directory == NULL || strlen(directory) == 0)
{
/* No argument given, change to the home directory */
new_dir = getenv("Home");
}
else if (strcmp(directory, "-") == 0)
{
/* Special case: change to the previous directory */
new_dir = getenv("OLDPWD");
if (new_dir == NULL)
{
write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
return;
}
write(STDOUT_FILENO, new_dir, strlen(new_dir));
write(STDOUT_FILENO, "\n", 1);
}
else
{
/* Change to the specified directory */
new_dir = directory;
}

if (chdir(new_dir) != 0)
{
write(STDERR_FILENO, "cd: error changing directory\n", 29);
}
else
{
/* Update the PWD environment variable */
char *cwd = getcwd(NULL, 0);
if (cwd != NULL)
{
setenv("PWD", cwd, 1);
free(cwd);
}
}
}
int main(int argc, char *argv[])
{
if (argc > 2)
{
write(STDERR_FILENO, "cd: too many arguments\n", 23);
return (1);
}

/* Pass the directory argument to the change_directory function */
change_directory((argc == 2) ? argv[1] : NULL);
return (0);
}

