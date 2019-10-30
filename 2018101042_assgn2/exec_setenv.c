/**
 * This function creates an environment variable varname and set its value to value
 * */

#include "shell.h"

void invalid_usage_setenv(char *c)
{
    print_err("Invalid usage: ");
    print_err("Correct usage: setenv varname [value]");
}

void exec_setenv(char *str, char **args)
{
    if (is_emptystr(args[1]))
        invalid_usage_setenv("Invalid usage: Too few arguments");
    else if (is_emptystr(args[2]))
    {
        if (setenv(args[1], "", 1) != 0)
            perror("cannot set variable");
    }
    else if (is_emptystr(args[3]))
    {
        if (setenv(args[1], args[2], 1) != 0)
            perror("cannot set variable");
    }
    else
        invalid_usage_setenv("Invalid usage: Too many arguments");
}