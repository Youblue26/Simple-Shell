#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int execute_command(const char *command)
{
int status = system(command);
if (status == -1)
{
perror("Failed to execute command");
return (-1);
}

if (WIFEXITED(status))
{
Check if the command exited normally
int exit_status = WEXITSTATUS(status);
return ((exit_status == 0) ? 1 : 0)
}
else
{
write(STDOUT_FILENO, "Command terminated by a signal\n", 30);
return (0);
}
}

void parse_commands(char *commands)
{
char *command = strtok(commands, "&&||");
while (command != NULL)
{
Remove leading/trailing whitespace
char *trimmed_command = strtok(command, " \t\n ");

int result;
if (strstr(trimmed_command, "&&"))
{
char *sub_command = strtok(trimmed_command, "&&");
result = 1;
while (sub_command != NULL)
{
result = result && execute_command(sub_command);
if (!result)
break;

sub_command = strtok(NULL, "&&");
}
}
else if (strstr(trimmed_command, "||"))
{
char *sub_command = strtok(trimmed_command, "||");
result = 0;

while (sub_command != NULL)
{
result = result || execute_command(sub_command);
if (result)
break;
sub_command = strtok(NULL, "||");
}
}
else
{
result = execute_command(trimmed_command);
}


char result_message[10];
sprintf(result_message, "%s\n", (result == 1) ? "Success" : "Failure");
write(STDOUT_FILENO, trimmed_command, strlen(trimmed_command));
write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, result_message, strlen(result_message));

command = strtok(NULL, "&&||");
}
}

int main(void)
{
char input_commands[256];
write(STDOUT_FILENO, "Enter commands: ", 16);
fgets(input_commands, sizeof(input_commands), stdin);

input_commands[strcspn(input_commands, "\n")] = '\0';

parse_commands(input_commands);

return (0);
}

