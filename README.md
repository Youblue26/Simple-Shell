Simple shell in C

A UNIX command line interpreter.
Writen by Ophelia Terlarbie ophiliate@gmail.com and Rebcca Akplome rakplome@gmail.com

Description

 A simple shell that execute custume commands and some built-ins. can take arguments as well

 Usage
 
To run the shell, compile all files in the repository and run executable file. from there, do as you woould in a UNIX environment To exit the shell, enter the command exit

Built-in commands

This shell has the following built-in commands:

exit - Exits the shell
env - Prints the current environment
cd - Changes the current directory
setenv - Sets an environment variable
unsetenv - Unsets an environment varriable

Functions

Function name	Description	File

main	The entry point of the shell	shell.c
bling	Prints the prompt	prompt.c
read_inputs	Reads the input from the user	prompt.c
parse_inputs	Parses the input into tokens	interpreter.c
exec_cmd	Executes the command	interpreter.c
cmd_ARGS	Executes a command if it is an absolute or relative path	interpreter.c
path_runs	checks if a command is in the PATH	
executer	Executes a command	
exec_cmd	Executes a command with arguments	interpreter.c
cd_hm	Changes the current directory to the home directory	cd_funcs.c
cd_prevs	Changes the current directory to the previous directory	cd_funcs.c
cd_path	Changes the current directory to a specified directory	cd_functions.c
cd_run	Changes the current directory	cd_functions.c
prints_env	Prints the current environment	builtin.c
sets_env	Sets an environment variable	builtin.c
unsets_env	Unsets an environment variable	builtin.c
ext_sh	Exits the shell	exit_shell.c
get_token	Gets the next token from a string	get_token.c
