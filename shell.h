#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

/**
 * struct var_input - struct
 * @count: count
 * @buffer: buffer
 * @array_inputs: array_inputs
 * @name_pro: name_pro
 * @exitstatus:exitstatus
 * typedef input_v: new name struct
 */
typedef struct var_input
{
	int count;
	char *buffer;
	char **array_inputs;
	char *name_pro;
	int exitstatus;
} input_v;

/**
 * struct com_struct - struct
 * @name: name
 * @p: p
 * typedef comand_v: new name struct
 */
typedef struct com_struct
{
	char *name;
	int (*p)(input_v *, char **);
} comand_v;

/**
 * struct com_help - struct
 * @name: name
 * @p: p
 * typedef input_v: new name struct
 */
typedef struct com_help
{
	char *name;
	char (*p)(input_v *);
} help_v;

/*utility functions*/
int check_for_comand(input_v *vars, char **env);
char **brokentoken(char *buffer, char *delimiter);
int comd_handling(input_v *vars, char **env);
char *get_enviroment(char **env, char *comd);
char *get_dir_concat(char **new_env, char *comd);
int take_env(input_v *vars, char **env);


/*methods function C*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strtok(char *line, char *delim);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *convers_integer(int count);
size_t _getline(char **buff);

/*Command functions*/
int exit_func(input_v *vars, char **env);

/*funtion Help*/
char *read_file(char *namefile);
int help_func(input_v *vars, char **env);
char (*help_match(input_v *vars))(input_v *vars);
char print_exit(input_v *vars);
char print_pwd(input_v *vars);
char print_cd(input_v *vars);
char print_help(input_v *vars);

int lsh_ctrld(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);
extern char **environ;
int lsh_exit(char **args);
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _putchar(char c);

char *_get_path(char **env);
int _values_path(char **arg, char **env);
char *_getline_command(void);
void _getenv(char **env);
char **tokenize(char *lineptr);
void _exit_command(char **args, char *lineptr, int _exit);
int _fork_fun(char **arg, char **av, char **env,
char *lineptr, int np, int c);

#endif
