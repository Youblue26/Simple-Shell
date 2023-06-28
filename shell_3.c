#include "shell.h"

/**
 * strn_cate - concatenates two strings
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to concatenate
 * Return: pointer to destination string
 */
char *strn_cate(char *dest, char *src, int n)
{
int i = 0;
int t = 0;

while (dest[i] != '\0')
i++;
while (src[t] != '\0' && t < n)
{
dest[i] = src[t];
i++;
t++;
}
dest[i] = '\0';
return (dest);
}

/**
 * strn_tok - tokenizes a string
 * @str: string
 * @delim: delimiter
 * @n: number of bytes to tokenize
 * Return: pointer to the tokenized string
 */
char *strn_tok(char *str, const char *delim, int n)
{
static char *token;
int i = 0;
int t = 0;
char *new;

if (str != NULL)
token = str;
while (token[i] != '\0' && i < n)
{
t = 0;
while (delim[t] != '\0')
{
if (token[i] == delim[t])
{
token = token + i + 1;
i = -1;
break;
}
t++;
}
i++;
}
if (token[0] == '\0')
return (NULL);
new = gets_token(token, delim, n);
return (new);
}

/**
 * str_chr - locates a character in a string
 * @str: string
 * @c: character to locate
 * Return: pointer to the first occurrence of the character
 */
char *str_chr(char *str, char c)
{
int i = 0;

while (str[i] != '\0')
{
if (str[i] == c)
return (str + i);
i++;
}
if (str[i] == c)
return (str + i);
return (NULL);
}

/**
 * _itoa - converts an integer to a string
 * @numb: integer to convert
 * Return: pointer to the converted string
 */
char *_itoa(int numb)
{
int i = 0;
int t = 0;
char *str = malloc(sizeof(char) * 1024);

if (str == NULL)
{
perror("Error");
return (NULL);
}
if (numb == 0)
{
str[i] = '0';
str[i + 1] = '\0';
return (str);
}
while (numb != 0)
{
str[i] = (numb % 10) + '0';
numb = numb / 10;
i++;
}
str[i] = '\0';
i--;
while (t < i)
{
str[t] = str[t] + str[i];
str[i] = str[t] - str[i];
str[t] = str[t] - str[i];
t++;
i--;
}
return (str);
}
