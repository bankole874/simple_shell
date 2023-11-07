#include "shell.h"

int main(void) {
	char command[120];

	while (true) {
		hm_view_prompt();
		hm_read_command(command, sizeof(command));
		hm_execute_command(command);
	}
	return 0;
}
