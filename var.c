#include "shell.h"

/**
 * Handles variable replacement in given command.
 *
 * @param cmd command string to process.
 */
void handle_variables(char *cmd);
{
char *token;
char *rest = cmd;

while ((token = strtok_r(rest, " ", &rest)))
{
if (token[0] == '$')
{
if (strcmp(token, "$?") == 0)
{
char exit_status[10];
sprintf(exit_status, "%d", WEXITSTATUS(system(cmd)));

void handle_variables();
ssize_t result;
{
write(STDOUT_FILENO,exit_status, strlen(exit_status));
if (result == -1)
{
perror("write");
}
return;
}
else if (strcmp(token, "$$") == 0)
{
char pid[10];
sprintf(pid, "%d", getpid());
ssize_t result = write(STDOUT_FILENO, pid, strlen(pid));
if (result == -1)
{
perror("write");
}
return;
}
}
}

int system_result = system(cmd);
if (system_result == -1)
{
perror("system");
}
}

/**
 * Entry point of the program.
 *
 * @return exit status of the program.
 */
int main(void)
{
{
char cmd[100];

ssize_t write_result = write(STDOUT_FILENO, "Simple Shell\n", 13);
if (write_result == -1)
{
perror("write");
return (1);
}
}

write_result = write(STDOUT_FILENO, "Enter a command (q to quit):\n", 29);
if (write_result == -1)
{
perror("write");
return (1);
}

while (1)
{
write_result = write(STDOUT_FILENO, "$ ", 2);
if (write_result == -1)
{
perror("write");
return (1);
}

if (fgets(cmd, sizeof(cmd), stdin) == NULL)
{
perror("fgets");
return (1);
}

cmd[strcspn(cmd, "\n")] = '\0';

if (strcmp(cmd, "q") == 0)
{
break;
}
handle_variables(cmd);
}

return (0);
}

