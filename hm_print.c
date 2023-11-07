#include "shell.h"

void hm_print(const char *message) {
	write(STDOUT_FILENO, message, strlen(message));
}
