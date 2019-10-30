// LIST OF ALL HEADER FILES

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <stddef.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
// Header files for readline and addtohistory commands
#include <readline/readline.h>
#include <readline/history.h>

// LIST OF ALL CONSTANTS USED

#define MAX_USERNAME_SIZE 1024
#define MAX_SYSTEM_NAME 1024
#define MAX_CURRENT_DIR 1024
#define MAX_LINE_LENGTH 1024
#define MAX_BUFFER_LENGTH 1024
#define MAX_COMMANDS_PER_LINE 1024
#define MAX_ARGUMENTS_PER_COMMAND 1024
#define MAX_SPID_LENGTH 10
#define MAX_HISTORY 20
#define MAX_JOBS 2048

// list of constants related to jobs
#define INVALID 0
#define FOREGROUND 1
#define BACKGROUND 2
#define STOPPED 3

// LIST OF ALL FUNCTION PROTOTYPES, GLOBAL VARIABLES, STRUCTURE DEFINITIONS

#ifndef SHELL_H
#define SHELL_H

// LIST OF GLOBAL VARIABLES

char home[MAX_CURRENT_DIR];
char history_path[MAX_CURRENT_DIR];
int isbg;
char history[1000000][MAX_LINE_LENGTH]; //history array to store history commands(can store maximum 100000 commands): should not go overflow
int history_lines;
int shellPID;
int ctrlc, ctrlz;
int is_already_displayed_strz;

// LIST OF ALL STRUCTURES USED

//structure of processes (running/stopped/current)
struct ongoing_processes // this is for the list of all the processes(both running and stopped)
{
    int pid;
    char name[1024];
};
struct ongoing_processes cur_fg;             // the current foreground process
struct ongoing_processes all_jobs[MAX_JOBS]; // list of all background and stopped processes in the order of creation
int jobs_size;                               //number of jobs

// LIST OF FUNCTION PROTOTYPES

// printing lines into stdout
void print(char *s);
void print_n(char *s);
void print_debug(char *s);
void printn_debug(char *s);
void print_err(char *s);

// error handling
void memory_error();
void file_error();

// globally used auxillary functions
int is_emptystr(char *str);
char *memalloc_str(int length);

// display features
char *display_shell_prompt();
void display_killed_children();

// read, intepret and run commands
char *read_command();
void interpret_command(char *cmd, int forcebg);
int execute_builtin_commands(char **args);
int execute_builtin_no_output(char **args);

// auxillary functions
int check_if_bg(char **args);
int isvalid_redirection(char **args);
int is_redirection_or_piping_char(char s);
char **string_splitter(char *buffer, char sep, int redirection);
void initialize_history();
void save_to_history(char *buffer);
void add_prev_history();
int get_status(struct ongoing_processes P);

// built-in commands
void exec_exit(char *arg, char **args);
void exec_echo(char *arg, char **args);
void exec_cd(char *arg, char **args);
void exec_pwd(char *arg, char **args);
void exec_pinfo(char *arg, char **args);
void exec_ls(char *arg, char **args);
void display_line_ls(char *filepath, char *filename);
void display_permissions_ls(int mode);
void exec_nightswatch(char *arg, char **args);
void exec_history(char *arg, char **args);
void exec_clearhistory(char *arg, char **args);
void exec_help(char *arg, char **args);
void exec_setenv(char *arg, char **args);
void exec_unsetenv(char *arg, char **args);
void exec_overkill(char *arg, char **args);
void exec_jobs(char *arg, char **args);
void exec_fg(char *arg, char **args);
void exec_bg(char *str, char **args);
void exec_kjob(char *str, char **args);
void exec_cronjob(char *arg, char **args);

// special stuff
void set_ip_op_redirection(char **args);
int pipe_handler(char *cmd);

// signal handlers
void sigtstpHandler(int sig_num);
void sigintHandler(int sig_num);

#endif