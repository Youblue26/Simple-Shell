#include "shell.h"

/**
 * get_line - reads an entire line from a file descriptor
 * @fd: file descriptor
 * Return: pointer to the line
 */
char *get_line(const int fd)
{
char *line = NULL;
char buff[1024];
int i = 0, t = 0, r = 0, n = 0;

while ((n = read(fd, buff, 1024)) > 0)
{
for (i = 0; i < n; i++)
{
if (buff[i] == '\n')
{
line = malloc(sizeof(char) * (t + 1));
if (line == NULL)
{
perror("Error: malloc failed");
return (NULL);
}
for (r = 0; r < t; r++)
line[r] = buff[r];
line[r] = '\0';
return (line);
}
t++;
}
}
return (line);
}
