#include "shell.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * @env: environ variable
 * Return: 0 if successfull
 */
int main(int ac, char **av, char **env)
{
if (ac == 1)
{
bling(av, env);
}
return (0);
}
