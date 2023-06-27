#include "shell.h"

void print_error(const char *message)
{
write(STDERR_FILENO, message, strlen(message));
}

int main(int argc, char *argv[])
{
if (argc < 2)
{
perror("Usage: myenv {setenv|unsetenv} VARIABLE [VALUE]\n");
return (1);
}

char *command = argv[1];
char *variable = argv[2];

if (strcmp(command, "setenv") == 0)
{
if (argc != 4)
{
perror("Usage: myenv setenv VARIABLE VALUE\n");
return (1);
}

char *value = argv[3];

if (setenv(variable, value, 1) != 0)
{
perror("Failed to set environ variable.\n");
return (1);
}

char success_message[128];
snprintf(success_message, sizeof(success_message),
		"Environ variable %s set to %s\n", variable, value);
write(STDOUT_FILENO, success_message, strlen(success_message));
}
else if (strcmp(command, "unsetenv") == 0)
{
if (argc != 3)
{
perror("Usage: myenv unsetenv VARIABLE\n");
return (1);
}

if (unsetenv(variable) != 0)
{
perror("Failed to unset environ variable.\n");
return (1);
}

char success_message[128];
snprintf(success_message, sizeof(success_message),
		"Environ variable %s unset.\n", variable);
write(STDOUT_FILENO, success_message, strlen(success_message));
}
else
{
perror("Unknown command. Available commands: setenv, unsetenv\n");
return (1);
}

return (0);
}
