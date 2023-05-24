#include "main.h"

/**
 * tokenize_str - Tokenize strings
 * Description: will tokenize, parse the string typed to do stdin
 * @tkn:-Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hshToken
 * @tkns: Tokens
 * @cmd: Command
 * @delim: Delimiter
 */

/*int tokenize_str(char *tkn, int tkns, char *cmd, const char *delim)
{
	tkn = strtok(cmd, delim);
	while (tkn != NULL)
	{
		tkns++;
		tkn = strtok(NULL, delim);
	}
	return tkns++;
}*/

/**
 * store_tokens - store token in the argv
 * Description: will store each token in the argv array
 * @tkn: token
 * @cmd:command
 * @arg: argv
 * @delim: Deleimiter
 * @i: index
 */

/*void store_tokens(char *tkn, char *cmd, char **arg, const char *delim, int i)
{
	tkn = strtok(cmd, delim);
	for (i = 0; tkn != NULL; i++)
	{
		arg[i] = malloc(sizeof(char) * string_length(tkn) + 1);
		make_string_copy(arg[i], tkn);
		tkn = strtok(NULL, delim);
	}
	arg[i] = NULL;
}*/

/**
 * get_path_var - this will get path variable
 * Description: this will get the path variable using **environ
 *
 * Return: NULL
 */
/*char* get_path_var()
{
	extern char **environ;
	char **env  = environ;

	while (*env != NULL)
	{
		char *current_env = *env;
		int i;
		for (i =  0; current_env[i] != '\0' && current_env[i] != '='; i++)
		{

		}
		if (string_compare(current_env, "PATH") == 0)
		{
			return current_env + i +1;
		}
		env++;
	}
	return NULL;
}*/

/**
 * get_path - get the variable path of sys
 * @cmd: content of the path to be tokenized
 * return: file_path which is full path or NULL
 */
char *get_path(char *cmd)
{
	char *path, *path_cpy, *p_token, *full_path;
	int path_len, cmd_len;
	struct stat buffer;

	path = getenv("PATH"); /* getenv(): I will impiment mine later */

	if (path)
	{
		path_cpy  = duplicate_string(path);
		cmd_len = string_length(cmd);
		p_token = strtok(path_cpy, ":");
		while (p_token != NULL)
		{
			path_len = string_length(p_token);
			full_path = malloc(cmd_len + path_len + 2);
			make_string_copy(full_path, p_token);
			string_cat(full_path, "/");
			string_cat(full_path, cmd);
			string_cat(full_path, "\0");

			if (stat(full_path, &buffer) == 0)
			{
				free(path_cpy);
				return (full_path);
			}
			else
			{
				free(full_path);
				p_token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(cmd, &buffer) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}

/**
 * execute_command - excute my commands
 * Description: this will excute the given commands
 * @argv: passed command
 */

void execute_command(char **argv)
{
	char *cmd = NULL;
	char *actual_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		actual_cmd = get_path(cmd);
		if (execve(actual_cmd, argv, NULL) == -1)
		{
			__print("./hsh: No such file or directory\n");
			/*perror("Oops!..");*/
		}
	}
}

