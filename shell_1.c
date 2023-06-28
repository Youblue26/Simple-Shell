#include "shell.h"

/**
 * str_compare - compares two strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0 if strings are equal, 1 if not
 */
int str_compare(char *str1, char *str2)
{
int i = 0;

while (str1[i] != '\0' && str2[i] != '\0')
{
if (str1[i] != str2[i])
return (1);
i++;
}
if (str1[i] != str2[i])
return (1);
return (0);
}

/**
 * str_dup - returns a pointer to a newly allocated space in memory
 * @str: string
* Return: pointer to new string
 */
char *str_dup(char *str)
{
char *ptr = NULL;
size_t length = str_len(str) + 1;
char *new = malloc(length);

if (str == NULL)
return (NULL);
ptr = strn_copy(new, str, length);
return (ptr);
new = malloc(length);
free(new);
}

/**
 * _atoi - converts a string to an integer
 * @str: string
 * Return: integer
 */
int _atoi(char *str)
{
int i = 0;
int sign = 1;
unsigned int numb = 0;
while (str[i] != '\0')
{
if (str[i] == '-')
sign *= -1;
if (str[i] >= '0' && str[i] <= '9')
{
numb = numb * 10 + (str[i] - '0');
if (str[i + 1] < '0' || str[i + 1] > '9')
break;
}
i++;
}
return (numb *sign);
}

/**
 * str_cate - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */
char *str_cate(char *dest, char *src)
{
int i = 0;
int t = 0;

while (dest[i] != '\0')
i++;
while (src[t] != '\0')
{
dest[i] = src[t];
i++;
t++;
}
dest[i] = '\0';
return (dest);
}

/**
 * str_len - returns the length of a string
 * @str: string
 * Return: length of string
 */
int str_len(char *str)
{
int i = 0;

while (str[i] != '\0')
i++;
return (i);
}
