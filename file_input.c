#include "shell.h"

void run_commands_from_file(const char *filename)
{
int file = open(filename, O_RDONLY);
if (file == -1)
{
const char *error_message = "file not found.\n";
ssize_t write_result = write(STDERR_FILENO,
error_message, strlen(error_message));
if (write_result == -1)
{
perror("write");
}
exit(1);
}

char command[MAX_COMMAND_LENGTH];
ssize_t bytesRead;
while ((bytesRead = read(file, command, sizeof(command) - 1)) > 0)
{

if (command[bytesRead - 1] == '\n')
{
command[bytesRead - 1] = '\0';
}
else
{
command[bytesRead] = '\0';
}

int status = system(command);
if (status == -1)
{
const char *error_message = "Error.\n";
ssize_t write_result = write(STDERR_FILENO,
error_message, strlen(error_message));
if (write_result == -1)
{
perror("write");
}
exit(1);
}
}
close(file);
}

int main(int argc, char *argv[])
{
if (argc != 2)
{
const char *error_message = "Usage: program_name [filename]\n";
ssize_t write_result = write(STDERR_FILENO,
error_message, strlen(error_message));
if (write_result == -1)
{
perror("write");
}
exit(1);
}
const char *filename = argv[1];
run_commands_from_file(filename);

return (0);
}
