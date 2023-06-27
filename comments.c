#include "shell.h"

/**
 * main entry point of the program
 * command  store the user's input and starts an infinite loop
 to continuously prompt the user for commands.
 */
int main(void)
{
char command[BUFFER_SIZE];

while (1)
{
ssize_t bytes_written = write(STDOUT_FILENO, " $ ", 3);
if (bytes_written == -1)
{
perror("write");
exit(EXIT_FAILURE);
}

ssize_t bytes_read = read(STDIN_FILENO, command, BUFFER_SIZE);
if (bytes_read == -1)
{
perror("read");
exit(EXIT_FAILURE);
}

if (command[0] == '\n' || command[0] == '#')
{
continue;
}

command[strcspn(command, "\n")] = '\0';

pid_t pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{

char *args[] = {"sh", "-c", command, NULL};
execve("/bin/sh", args, NULL);
perror("execve");
exit(EXIT_FAILURE);
}
else
{

int status;
waitpid(pid, &status, 0);
}
}

return (0);
}

