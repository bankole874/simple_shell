#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

void hm_view_prompt(void);
void hm_print(const char *message);
void hm_read_command(char *command, size_t size);
void hm_execute_command(const char *command);




#endif /* SHELL_H */
