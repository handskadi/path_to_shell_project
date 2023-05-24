#include "main.h"

/**
 * main - Simple Shell Project
 * Description: C project that memics the bash shell and 
 *	Thomson shell. This shell will, Reads, evaluate 
 *	and excute simple commands.
 * @argc:commands counts
 * @argv: commands
 * Return: 0 Always sucess.
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		shell_p(av, env);
	}

	return (0);
}
