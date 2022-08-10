#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
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
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

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

/* handle built ins */
int checker(char **cmd, char *buf);
void prompt_user(void);
void handle_signal(int m);
char **tokenizer(char *line);
char *test_path(char **path, char *command);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void exit_cmd(char **command, char *line);

/* prin environment */
void print_env(void);

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
int _strncmp(char *s1, char *s2, int n);
char *_strchr(char *s, char c);
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

void execution(char *cp, char **cmd);
char *find_path(void);

/* helper function for efficient free */
void free_buffers(char **buf);

/**
 * struct builtin - contain bultin to handle and function to excute
 */
struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * struct bulltin - contain bultin to handle and function to excute
 */
struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif
