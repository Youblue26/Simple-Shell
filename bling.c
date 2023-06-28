#include "shell.h"

/**
 * bling - displays the prompt
 * Return: void
 */
void bling(void)
{
write(STDOUT_FILENO, "$ ", 2);
}
