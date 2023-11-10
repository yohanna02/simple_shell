#ifndef __MAIN_H__
#define __MAIN_H__

#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <stdio.h>

extern char **environ;

#define PROMPT_MSG "$ "
#define PROMPT_LEN 2

#define UNUSED(x) (void)(x)

#ifndef PATH_MAX /* PATH_MAX is defined in limits.h */
#define PATH_MAX 1024
#endif /* PATH_MAX */

/**
 * struct info - Stores shell data
 * @line: commands typed
 * @interactive: shell mode
 * @shell_name: name of the shell
 * @exit_code: exit code of the shell
*/
typedef struct info
{
	char *line;
	int interactive;
	char shell_name[5];
	int exit_code;
	char **environ;
} info_t;

/**
 * struct cmd - command structure
 * @command: format specifier
 * @f: command function
*/
typedef struct cmd
{
	char *command;
	void (*f)(info_t *);
} command_t;

void prompt(info_t *shell_data);
void (*select_cmd(char *cmd))(info_t *);
char *_getenv(char *variable);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
char *_strtok(char *str, const char *delim);
size_t _strcspn(const char *str, const char *reject);
size_t _strspn(const char *str, const char *accept);
char *_strtok(char *str, const char *delim);
pid_t _fork(void);
char *get_exec_path(char *program);
char **get_argv(char *line);
void free_multiple(int count, ...);
void free_array(void **array, int array_size);
void *_realloc(void *ptr, size_t size);
void *_malloc(size_t size);
char *_strdup(const char *s);
void run_cmd(info_t *);
void _exec(info_t *);
void cmd_exit(info_t *);
void cmd_env(info_t *);
void cmd_setenv(info_t *);
int _setenv(char *name, char *value, int overwrite);
void init_env(info_t *);
int _atoi(char *s);
int is_valid_number(const char *str);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _cd(const char *path);
void cmd_cd(info_t *shell_data);

/* Custom Print function */
#define BUFFER_SIZE 1024

int add_to_buffer(int fd, char *buffer, int *buffer_index, char c);
void flush_buffer(int fd, char *buffer, int *buffer_index);

/**
 * struct spec  - specifier structure
 * @specifier: format specifier
 * @f: format specifier function
*/
typedef struct spec
{
	char specifier;
	int (*f)(int, va_list, char *, int *);
} specifier_t;

int _dprintf(int fd, const char *format, ...);
int (*select_specifier(char specifier))(int, va_list, char *, int *);
int print_string(int, va_list, char *, int *);
int print_char(int, va_list, char *, int *);
int print_number(int, va_list, char *, int *);

#endif /* __MAIN_H__ */
