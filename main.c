#include "shell.h"
/**
 * handle_ctrld - simple shell
 * @vars: argument count
 * @len: argument vectors
 */
void handle_ctrld(input_v *vars, int len)
{
	if (len == -1)
	{
		free(vars->buffer);
		/*free(vars->array_inputs);*/
		exit(0);
	}
}

/**
 * main - Main arguments functions
 * @ac: Count of argumnents
 * @av: Arguments
 * @env: Environment
 * Return: _exit = 0.
 */
int shell(int ac, char **av, char **env)
{
	int pathValue = 0, status = 0, is_path = 0;
	char *line = NULL, /**ptr to inpt*/ **commands = NULL; /**tokenized commands*/
	(void)ac;
	while (1)/* loop until exit */
	{
		errno = 0;
		line = _getline_command();/** reads user input*/
		if (line == NULL && errno == 0)
			return (0);
		if (line)
		{
			pathValue++;
			commands = tokenize(line);/** tokenizes or parse user input*/
			if (!commands)
				free(line);
			if (!_strcmp(commands[0], "env"))/**checks if user wrote env"*/
				_getenv(env);
			else
			{
				is_path = _values_path(&commands[0], env);/** tokenizes PATH*/
				status = _fork_fun(commands, av, env, line, pathValue, is_path);
					if (status == 200)
					{
						free(line);
						return (0);
					}
				if (is_path == 0)
					free(commands[0]);
			}
			free(commands); /*free up memory*/
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);/** Writes to standard output*/
			exit(status);
		}
		free(line);
	}
	return (status);
}

/**
 * main - function that evaluates whether the command exists
 * @ac: count
 * @av: array
 * @env: enviroment
 * Return: message
 */
int main(int ac, char **av, char **env)
{
	int shell(int ac, char **av, char **env);
	input_v var = {0, NULL, NULL, NULL, 0};
	size_t cant_buff = 0;
	ssize_t len = 0;
	char delimit[] = " \n\r\t";

	(void)ac;
	var.name_pro = av[0];
	if (isatty(STDIN_FILENO))
		write(1, "#cisfun$ ", 9);
	while ((len = getline(&(var.buffer), &cant_buff, stdin)) != -1)
	{
		var.count++;
		if (len > 1 && *var.buffer != '\n')
		{
			var.array_inputs = brokentoken(var.buffer, delimit);
			if (var.array_inputs[0] != NULL)
			{
				var.exitstatus = check_for_comand(&var, env);
				if (var.exitstatus == 0)
					var.exitstatus =
						comd_handling(&var, env);
			}
			else
				free(var.array_inputs);
		}
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
	}
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
	handle_ctrld(&var, len);
	return (var.exitstatus);
}
