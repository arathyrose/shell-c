
# OS ASSIGNMENT 1

## AIM

To Implement a shell which supports semi-colon separated list of commands.

## PRE-REQUISITES

You need to have the readline package installed.
For ubuntu 18 you can use ```sudo apt install libreadline-dev```

## TO RUN

To run the shell, perform the following commands:
> make  
> ./shell

## BUILTIN COMMANDS SUPPORTED

* exit
* quit
* echo
* pwd
* ls
* pinfo
* nightswatch
* history
* clearhistory
* jobs
* overkill
* fg
* bg
* cronjob
* cd
* setenv
* unsetenv
* kjob
* help

## FILES USED

| FILE NAME                  | DESCRIPTION                                                                                                                                      |
|----------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------|
| Makefile                   | contains all the instructions required to make and run the shell.                                                                                |
| shell.h                    | contains the list of all header files, constants, global variables, and function prototypes                                                      |
| main.c                     | contains the main function which runs the shell                                                                                                  |
| display_killed_children.c  | Display the name and pid of all children killed or stopped                                                                                       |
| display_shell_prompt.c     | Displays the shell prompt (specification 1)                                                                                                      |
| read_command.c             | Reads a line(ending with EOL or '\n') from the command prompt, and removes all leading, trailing and consecutive white spaces(' ' '\v' and '\t') |
| interpret_command.c        | Considers a command stored in the buffer and parses it and executes them based on whether it is builtin or not                                   |
| string_splitter.c          | This function parses the string based on some separator (a function similar to strok command).                                                   |
| execute_builtin_commands.c | This code executes all builtin commands by calling those particular functions.                                                                   |
| exec_cd.c                  | Implements cd command by changing the directory                                                                                                  |
| exec_echo.c                | Implements echo command, that is, prints all the arguments to this function to stdout.                                                           |
| exec_exit.c                | Exits the shell normally and successfully                                                                                                        |
| exec_pwd.c                 | Prints the current/present working directory                                                                                                     |
| exec_pinfo.c               | Displays the pinfo of the process using the pid given                                                                                            |
| exec_ls.c                  | Implements the ls command by listing all items in a directory                                                                                    |
| display_line_ls.c          | display the file details when the command ls -l is called                                                                                        |
| display_permissions_ls.c   | displays the permissions of the file, given its mode                                                                                             |
| check_if_bg.c              | This function checks whether the given parsed string (separated by spaces) can qualify as a background process or not.                           |
| print.c                    | This file contains the functions to prints a given string to stdout and some basic error handling (memory error)                                 |
| exec_nightswatch.c         | Implements nightswatch.                                                                                                                          |
| exec_history.c             | Displays the last 20 or argument number of previous commands entered                                                                             |
| exec_builtin.c             | Displays the list of all builtin commands supported by the shell                                                                                 |

### TO UNDERSTAND HOW EACH FILE WORKS OR WHAT EACH FILE CONTAINS, KINDLY OPEN EACH FILE AND CHECK.
