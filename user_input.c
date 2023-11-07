#include "shell.h"

void hm_read_command(char *command, size_t size) {
	if (fgets(command, size, stdin) == NULL) {
	        if (feof(stdin)) {
        		hm_print("\n");
            	exit(EXIT_SUCCESS);
        	} else {
            		hm_print("Error while reading input.\n");
            		exit(EXIT_FAILURE);
        	}
    	}
    	command[strcspn(command, "\n")] = '\0';
}
