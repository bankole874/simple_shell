#include "shell.h"

void hm_execute_command(const char *command) {
	pid_t hm_child_pid = fork();

	if (hm_child_pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);

	} else if (hm_child_pid == 0) {
		 execlp(command, command, (char *)NULL);
		 perror("execlp");
		 exit(EXIT_FAILURE);
	} else {
		wait(NULL);
	}
}
