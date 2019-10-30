/**
 * This function exits out of all the processes and then exits the shell normally and successfully
 */

#include "shell.h"

void exec_exit(char *str, char **args)
{
    exec_overkill(str, args);
    print_n("Exiting the shell now...");
    exit(EXIT_SUCCESS);
}