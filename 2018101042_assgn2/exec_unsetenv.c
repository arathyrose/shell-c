/**
 * This function destroys an environment variable of name varname 
 * */

#include "shell.h"

void invalid_usage_unsetenv(char *c)
{
    print_err(c);
    print_err("Correct usage: unsetenv varname");
}

void exec_unsetenv(char *str, char **args)
{
    if (is_emptystr(args[1]))
        invalid_usage_unsetenv("Invalid usage: Too few arguments");
    else if (is_emptystr(args[2]))
    {
        if (unsetenv(args[1]) != 0)
            perror("cannot unset variable");
    }
    else
        invalid_usage_unsetenv("Invalid usage: Too many arguments");
}