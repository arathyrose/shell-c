/**
 * This function displays the list of all the jobs (background and stopped) that are still running/stopped and had been started by the shell
 */

#include "shell.h"

void display_jobs_line(int c, struct ongoing_processes proc, char *stat)
{
    char *buffer = memalloc_str(MAX_LINE_LENGTH * 4);
    sprintf(buffer, " [%d] %s %s [%d]", c, stat, proc.name, proc.pid);
    print_n(buffer);
    free(buffer);
}

void exec_jobs(char *arg, char **args)
{
    if (!is_emptystr(args[1]))
        print_n("Invalid format: too many arguments!");
    else
    {
        int c = 0;
        for (int i = 0; i < jobs_size; i++)
        {
            int type=get_status(all_jobs[i]);
            if (type != INVALID)
                c++;
            if (type == BACKGROUND)
                display_jobs_line(c, all_jobs[i], "Running");
            if (type == STOPPED)
                display_jobs_line(c, all_jobs[i], "Stopped");
        }
    }
}
