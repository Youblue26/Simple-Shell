#include "shell.h"

void run_command(const char *command)
{
system(command);
}

void run_commands(const char *commands)
{
char *command_copy = strdup(commands);
char *token = strtok(command_copy, ";");

while (token != NULL)
{
char *command = strdup(token);
command[strcspn(command, "\n")] = '\0';

if (strlen(command) > 0)
{
run_command(command);
}

free(command);
token = strtok(NULL, ";");
}

free(command_copy);
}
int main(void)
{
while (1)
{
char commands[1000];
write(STDOUT_FILENO, "Enter command ('exit' to quit): ", 33);
fgets(commands, sizeof(commands), stdin);

if (strcmp(commands, "exit\n") == 0)
{
break;
}

run_commands(commands);
}

return (0);
}
