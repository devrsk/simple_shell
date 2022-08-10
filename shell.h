#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/**
 * struct builtin - is a structure for a builtin object
 * @env: is the environment element
 * @exit: is the exit element
 */

struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * struct flags - is a structure for a flag object
 * @interactive: is the interactive element
 */

struct flags
{
	bool interactive;
} flags;

/**
 * struct info - is a structure for information object
 * @final_exit: is the final exit element
 * @ln_count: is the line count element
 */

struct info
{
	int final_exit;
	int ln_count;
} info;


int _putchar(char c);
int print_s(char *s);
int main(int ac, char **av, char *envp[]);
int handle_builtin(char **command, char *line);
void print_env(void);
void exit_cmd(char **command, char *line);
int checker(char **cmd, char *buf);
char *append_path(char *path, char *command);
void handle_signal(int m);
char *test_path(char **path, char *command);
int handle_builtin(char **command, char *line);
char **tokenizer(char *line);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);
void execution(char *cp, char **cmd);
char *find_path(void);
void prompt_user(void);
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
void free_buffers(char **buf);


#endif
