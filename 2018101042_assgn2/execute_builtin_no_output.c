/**
 * This code executes all builtin commands that do not produce an output that can be sent anywhere or cannot be done in a child process
 * It returns 1 if the command is executed. 
 * It returns 0 if the command is not executed
 */

#include "shell.h"

int execute_builtin_no_output(char **args)
{
    if (strcmp(args[0], "exit") == 0)
        exec_exit(args[0], args);
    else if (strcmp(args[0], "quit") == 0)
        exec_exit(args[0], args);
    else if (strcmp(args[0], "cd") == 0)
        exec_cd(args[0], args);
    else if (strcmp(args[0], "setenv") == 0)
        exec_setenv(args[0], args);
    else if (strcmp(args[0], "unsetenv") == 0)
        exec_unsetenv(args[0], args);
    else if (strcmp(args[0], "overkill") == 0)
        exec_overkill(args[0], args);
    else if (strcmp(args[0], "fg") == 0)
        exec_fg(args[0], args);
    else if (strcmp(args[0], "bg") == 0)
        exec_bg(args[0], args);
    else if (strcmp(args[0], "kjob") == 0)
        exec_kjob(args[0], args);
    else if (strcmp(args[0], "clearhistory") == 0)
        exec_clearhistory(args[0], args);
    else
        return 0;
    return 1;
}
