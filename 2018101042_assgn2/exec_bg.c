/**
 * This function brings a stopped process (i.e. a foreground process that was stopped by giving a STP signal (by pressing CTRL-Z)) to a running/sleeping state in the background (as a background process)
 **/

#include "shell.h"

int debug_exec_bg = 0;

void exec_bg(char *str, char **args)
{
    if (is_emptystr(args[1]))
    {
        print_err("Invalid usage: job number not found! \nUsage: bg jobno");
        return;
    }
    if (!is_emptystr(args[2]))
    {
        print_err("Invalid usage: Too many arguments! \nUsage: bg jobno");
        return;
    }
    if (debug_exec_bg)
        print_n(args[1]);
    int job_no;
    job_no = atoi(args[1]);
    if (job_no <= 0)
    {
        print_err("Invalid usage: Invalid job number! \nUsage: bg jobno");
        return;
    }
    int c = 0;
    for (int i = 0; i < jobs_size; i++)
    {
        if (get_status(all_jobs[i]) != INVALID)
        {
            c++;
            if (c == job_no)
            {
                kill(all_jobs[i].pid, SIGCONT); // SIGCONT continues in background a process previously stopped by SIGSTOP or SIGTSTP.
                // all_jobs[i].type = BACKGROUND;
                return;
            }
        }
    }
    print_err("Error: Job number does not exist");
    return;
}