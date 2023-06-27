#include "shell.h"

char name[] = "MAX_ALIAS-VALUE";
char value[] =  "MAX_ALIAS_VALUE";
int numAliases;

/**
 * print_aliases - Prints all aliases stored in AliasData structure
 * @data: Points to AliasData structure
 */
struct AliasData;
int numAliases;

void print_aliases(const struct AliasData *data)
{
int i;
for (i = 0; i < data->numAliases; i++)
{
char buffer[256];
int len = snprintf(buffer, sizeof(buffer), "%s='%s'\n",
data->aliases[i].name, data->aliases[i].value);
write(STDOUT_FILENO, buffer, len);
}
}

/**
 * print_alias - prints the alias with the specified name
 * @data: pointer to AliasData structure
 * @name: name of the alias to print
 */
void print_alias(const struct AliasData *data, const char *name)
{
int i;
for (i = 0; i < data->numAliases; i++)
{
if (strcmp(data->aliases[i].name, name) == 0)
{
char buffer[256];
int len = snprintf(buffer, sizeof(buffer), "%s='%s'\n",
data->aliases[i].name, data->aliases[i].value);
write(STDOUT_FILENO, buffer, len);
return;
}
}
}

/**
 * set_alias - Defines alias with the given name and value or
  updates the value of an existing alias
 * @data: pointer to AliasData structure
 * @name: name of the alias to set
 * @value: value of the alias
 */
void set_alias(struct AliasData *data, const char *name, const char *value)
{
int (i);
for (i = 0; i < data->numAliases; i++)
{
if (strcmp(data->aliases[i].name, name) == 0)
{
strcpy(data->aliases[i].value, value);
return;
}
}

if (data->numAliases < MAX_ALIASES)
{
strcpy(data->aliases[data->numAliases].name, name);
strcpy(data->aliases[data->numAliases].value, value);
data->numAliases++;
}
else
{
write(STDOUT_FILENO, "Maximum number of aliases reached.\n", 34);
}
}

/**
 * process_alias_command - Processes alias command with a  given arguments
 * @data: pointer to AliasData structure
 * @argc: number of arguments
 * @argv: array of argument strings
 */
void process_alias_command(struct AliasData *data, int argc, char *argv[])
{
if (argc == 1)
{
print_alias(data, name);
}
else if (argc == 2)
{
print_alias(data, argv[1]);
}
else
{
int (i);
for ( i = 1; i < argc; i++)
{
char *arg = argv[i];
char *equalSign = strchr(arg, '=');
if (equalSign != NULL)
{
*equalSign = '\0';
set_alias(data, arg, equalSign + 1);
}
else
{
print_alias(data, arg);
}
}
}
}

/**
 * main - entry point of the program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, non-zero on fail
 */

struct AliasData
{
int numAliases;
char** aliases;
};
int main(int argc, char *argv[])
{
struct AliasData data;
data.numAliases = 0;
process_alias_command(&data, argc, argv);
return (0);
}

