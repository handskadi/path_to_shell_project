#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int string_length(const char *str);
char *make_string_copy(char *destination, char *source);
void __print(const char *string);
char *string_cat(char *dest, char *src);
char *duplicate_string(const char *string);
int string_compare(char *str1, char *str2);
void shell_p(char **av, char **env);
char *get_path(char *cmd);
void execute_command(char **argv);

#endif
