#ifndef UTIL_H
#define UTIL_H
/**
 * string_length - count string length
 * description: this fuction will return number
 *	of characters in a string
 * @str: string to be counted
 * Return: length - number of characters
 */
size_t string_length(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * make_string_copy - makeopy of string
 * Description: This will make copy of string
 *	from source to destination
 * @destination: string destination
 * @source: source of string
 */

void make_string_copy(char *destination, const char *source)
{
	while (*source)
	{
		*destination = *source;
		source++;
		destination++;
	}

	*destination = '\0';
}

/**
 * __print - Print function
 * Description: This will print string using write
 *	without using string_length
 * @string: string to be printed
 * Return: string of chars
 */

char __print(const char *string)
{
	write(STDOUT_FILENO, string, string_length(string));
}


/**
 * tokenize_str - Tokenize strings
 * Description: will tokenize, parse the string typed to do stdin
 * @tkn: Token
 * @tkns: Tokens
 * @cmd: Command
 * @delim: Delimiter
 */

void tokenize_str(char *tkn, int tkns, char *cmd, const char *delim)
{
	tkn = strtok(cmd, delim);
	while (tkn != NULL)
	{
		tkns++;
		tkn = strtok(NULL, delim);
	}
	tkns++;
}

/**
 * store_tokens - store token in the argv
 * Description: will store each token in the argv array
 * @tkn: token
 * @cmd:command
 * @arg: argv
 * @delim: Deleimiter
 * @i: index
 */

void store_tokens(char *tkn, char *cmd, char **arg, const char *delim, int i)
{
	tkn = strtok(cmd, delim);
	for (i = 0; tkn != NULL; i++)
	{
		arg[i] = malloc(sizeof(char) * string_length(tkn));
		make_string_copy(arg[i], tkn);
		tkn = strtok(NULL, delim);
	}
	arg[i] = NULL;
}

/**
 * execute_command - excute my commands
 * Description: this will excute the given commands
 * @argv: passed command
 */
void execute_command(char **argv)
{
	char *cmd = NULL;

	if (argv)
	{
		/* Grab my cmd */
		cmd = argv[0];

		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Oops!..");
		}
	}
}
#endif
