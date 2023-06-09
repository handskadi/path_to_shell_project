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
	int isEOF = 1, index = 0, tokens = 0, argc, status;
	size_t n = 0;
	ssize_t cmd_count;
	const char *delimiter = " \n";
	char *shell_prompt = "Alx-Shell> ", *EOF_message = "Bye.. \n";
	pid_t momo_pid;

	(void)argc;

	while (isEOF)
	{
		__print(shell_prompt);
		cmd_count = getline(&cmd, &n, stdin);

		if (cmd_count == -1)
		{
			__print(EOF_message);
			exit(EXIT_FAILURE);
			free(cmd);
			free(cmd_copy);
			isEOF = 0;
			break;
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

			momo_pid = fork();
			if (momo_pid == -1)
			{
				free(cmd_copy);
				free(cmd);
				exit(EXIT_FAILURE);
			}
			
			if (momo_pid == 0)
			{
				/* Run the commands */
				execute_command(argv);
			}
			else
			{
				wait(&status);
			}			
		}
	}
	free(cmd_copy);
	free(cmd);
	return (0);
}
