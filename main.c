#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "sysutil.h"
#include "util.h"

/**
 * main - Alx Shell Project
 * Description: Simple shell that reads commands, tokenize them
 *	and excute them. Made by KADI Mohamed & Souhail KADIRI
 * @void: void
 * Return: 0 always success
 */

int main(void)
{
	char *cmd = NULL, *cmd_copy = NULL, *token, **argv;
	int isEOF = 1, index = 0, tokens = 0, argc;
	size_t n = 0;
	ssize_t cmd_count;
	const char *delimiter = " \n";
	char *shell_prompt = "Alx-Shell> ", *EOF_message = "Bye.. \n";

	(void)argc;

	while (isEOF)
	{
		__print(shell_prompt);
		cmd_count = getline(&cmd, &n, stdin);

		if (cmd_count == -1)
		{
			__print(EOF_message);
			return (-1);
		}
		cmd_copy = malloc(sizeof(char) * cmd_count);
		if (cmd_copy == NULL)
		{
			perror("Unscuessful Allocation");
			return (-1);
		}
		else
		{
			make_string_copy(cmd_copy, cmd);
			token = strtok(cmd, delimiter);
			tokenize_str(token, tokens, cmd, delimiter);
			argv = malloc(sizeof(char *) * tokens);
			store_tokens(token, cmd_copy, argv, delimiter, index);

			/* Run the commands */
			execute_command(argv);
		}
	}
	free(cmd_copy);
	free(cmd);
	return (0);
}

