#include "main.h"
#define MAX_CMD 15

/**
 * shell_p - Prompt
 * Description: my shell will go on infinite loop to show always prompt to user
 * @argv: command passed by user
 * @env: Enviroment Variable
 * Return: 0 Always success
 */

void shell_p(char **av, char **env)
{
	char *shell_prompt = "#cisfun$ ", *argv[MAX_CMD];
	char *cmd = NULL, *delimiter = " ";
	size_t n = 25;
	int cmd_index, strtok_index, wait_status;
	ssize_t cmd_char_num;
	pid_t pid;

	while (1) 
	{
		if (isatty(STDIN_FILENO))
		{
			__print(shell_prompt);
		}
		cmd = malloc(sizeof(char) * n);
		cmd_char_num = getline(&cmd, &n, stdin);
		if (cmd_char_num == -1)
		{
			free(cmd);
			__print("\n");
			exit(EXIT_FAILURE);
		}
		cmd_index = 0;
		while (cmd[cmd_index])
		{
			if (cmd[cmd_index] == '\n')
			{
				cmd[cmd_index] = 0;
			}
			cmd_index++;
		}
		strtok_index = 0;
		argv[strtok_index] = strtok(cmd, delimiter);
		while (argv[strtok_index] != NULL)
		{
			strtok_index++;
			argv[strtok_index] = strtok(NULL, delimiter);
		}
		pid = fork();
		if (pid < 0)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			/*if (execve(argv[0], argv, env) == -1)
			{
				(void)av;
				__print("./hsh: No such file or directory \n");
			};*/
			(void)env;
			(void)av;
			execute_command(argv);
		
		} 
		else
		{
			wait(&wait_status);
		}

	}
	
}
