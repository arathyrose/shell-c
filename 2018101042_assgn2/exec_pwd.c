/**
 * This function prints the current/present working directory
 */

#include "shell.h"

void exec_pwd(char *arg, char **args)
{
    if (!is_emptystr(args[1]))
        print_n("pwd: too many arguments\n");
    else
    {
        char *buffer = memalloc_str(MAX_CURRENT_DIR);
        getcwd(buffer, MAX_CURRENT_DIR); //this would give the absolute working directory
        print_n(buffer);
        free(buffer);
    }
}