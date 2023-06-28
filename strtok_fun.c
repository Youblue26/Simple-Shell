#include "shell.h"

/**
 * gets_token - gets the token
 * @token: token
 * @delim: delimiter
 * @n: number of bytes to tokenize
 * Return: pointer to the tokenized string
 */
char *gets_token(char *token, const char *delim, int n)
{
int i = 0;
int t = 0;
int r = 0;
char *new;

i = 0;
while (token[i] != '\0' && i < n)
{
t = 0;
while (delim[t] != '\0')
{
if (token[i] == delim[t])
{
new = malloc(sizeof(char) * (i + 1));
if (new == NULL)
{
perror("Error: ");
return (NULL);
}
new[i] = '\0';
return (new);
}
t++;
}
i++;
}
new = malloc(sizeof(char) * (i + 1));
if (new == NULL)
{
perror("Error: ");
return (NULL);
}
for (r = 0; r < i; r++)
new[r] = token[r];
new[r] = '\0';
token = token + i;
return (new);
}
