#include "shell.h"

/**
 * strn_compare - compares two strings
 * @str1: string 1
 * @str2: string 2
 * @n: number of bytes to compare
 * Return: 0 if strings are equal, 1 if not
 */
int strn_compare(char *str1, char *str2, int n)
{
int i = 0;

while (str1[i] != '\0' && str2[i] != '\0' && i < n)
{
if (str1[i] != str2[i])
return (1);
i++;
}
if (str1[i] != str2[i] && i < n)
return (1);
return (0);
}

/**
 * get_env - gets the value of an environment variable
 * @name: name of the environment variable
* Return: value of the environment variable
 */
char *get_env(char *name)
{
int i = 0;
char *env_var;
char *env_val = NULL;
size_t length;

length = str_len(name);

while (environ[i] != NULL)
{
env_var = environ[i];
if (strn_compare(env_var, name, length) == 0 && env_var[length] == '=')
{
env_val = env_var + length + 1;
return (env_val);
}
i++;
}
return (NULL);
}

/**
 * str_tok - tokenizes a string
* @str: string
 * @delim: delimiter
 * Return: pointer to the tokenized string
 */
char *str_tok(char *str, const char *delim)
{
static char *save;
char *token;
int i = 0, t = 0;

if (str == NULL)
str = save;
while (str[i] != '\0')
{
while (delim[t] != '\0')
{
if (str[i] == delim[t])
{
str[i] = '\0';
save = &str[i + 1];
return (str);
}
t++;
}
t = 0;
i++;
}
if (str[i] == '\0')
{
save = &str[i];
return (str);
}
token = NULL;
return (token);
}

/**
 * strn_copy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to copy
 * Return: pointer to the destination string
 */
char *strn_copy(char *dest, char *src, int n)
{
int i = 0;

while (src[i] != '\0' && i < n)
{
dest[i] = src[i];
i++;
}
while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}

/**
 * str_copy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to the destination string
 */
char *str_copy(char *dest, const char *src)
{
int i = 0;

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}
