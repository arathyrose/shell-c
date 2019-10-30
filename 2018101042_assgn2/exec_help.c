/**
 * This function displays the list of all builtin commands supported by the shell
 */

#include "shell.h"

void exec_help(char *arg, char **args)
{
    print_n("List of commands supported: ");
    print_n("\texit");
    print_n("\tquit");
    print_n("\techo");
    print_n("\tpwd");
    print_n("\tls");
    print_n("\tpinfo");
    print_n("\tnightswatch");
    print_n("\thistory");
    print_n("\tclearhistory");
    print_n("\tjobs");
    print_n("\toverkill");
    print_n("\tfg");
    print_n("\tbg");
    print_n("\tcronjob");
    print_n("\tcd");
    print_n("\tsetenv");
    print_n("\tunsetenv");
    print_n("\tkjob");
}