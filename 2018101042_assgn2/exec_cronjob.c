/**
 * This function executes the cronjob function, that is, execute a command c every t seconds for p time interval
 */

#include "shell.h"

int debug_exec_cronjob = 0;

void invalid_usage_cron(char *s)
{
    print_err(s);
    print_err("Usage: cronjob -c cmd -t time -p period");
    exit(0);
}

void exec_cronjob(char *arg, char **args)
{
    int is_flags_read[3] = {0, 0, 0}, p, t;
    char **cmd = (char **)malloc(MAX_COMMANDS_PER_LINE * sizeof(char *));
    if (!cmd)
        memory_error();
    char *cmd_str = memalloc_str(MAX_LINE_LENGTH);
    for (int i = 1; !is_emptystr(args[i]); i++)
    {
        if (debug_exec_cronjob)
            printn_debug(args[i]);
        if (strcmp(args[i], "-c") == 0 && is_flags_read[0] == 0)
        {
            i++;
            int cmd_length = 0;
            if (is_emptystr(args[i]))
                invalid_usage_cron("Invalid usage: No command provided");
            for (; !is_emptystr(args[i]) && strcmp(args[i], "-c") && strcmp(args[i], "-p") && strcmp(args[i], "-t"); i++)
            {
                cmd[cmd_length] = memalloc_str(MAX_ARGUMENTS_PER_COMMAND);
                if (!cmd[cmd_length])
                    memory_error();
                strcpy(cmd[cmd_length], args[i]);
                cmd_length++;
            }
            cmd[cmd_length++] = NULL;
            is_flags_read[0] = 1;
            i--;
            cmd_str[0] = '\0';
            for (int i = 0; !is_emptystr(cmd[i]); i++)
            {
                strcat(cmd_str, cmd[i]);
                strcat(cmd_str, " ");
            }
            if (debug_exec_cronjob)
                printn_debug(cmd_str);
        }
        else if (strcmp(args[i], "-t") == 0 && is_flags_read[1] == 0)
        {
            i++;
            if (is_emptystr(args[i]))
                invalid_usage_cron("Invalid usage: No time provided");
            t = atoi(args[i]);
            if (!t)
                invalid_usage_cron("Invalid usage: Invalid time");
            is_flags_read[1] = 1;
        }
        else if (strcmp(args[i], "-p") == 0 && is_flags_read[2] == 0)
        {
            i++;
            if (is_emptystr(args[i]))
                invalid_usage_cron("Invalid usage: No period provided");
            p = atoi(args[i]);
            if (!p)
                invalid_usage_cron("Invalid usage: Invalid period");
            is_flags_read[2] = 1;
        }
        else
            invalid_usage_cron("Invalid usage: Invalid format");
    }
    if (!is_flags_read[0] || !is_flags_read[1] || !is_flags_read[0])
        invalid_usage_cron("Invalid usage: Invalid format");
    if (debug_exec_cronjob)
    {
        char *buffer = memalloc_str(MAX_LINE_LENGTH);
        sprintf(buffer, "COMMAND: %s  Time: %d   Period: %d", cmd_str, t, p);
        printn_debug(buffer);
        free(buffer);
    }
    int no_of_times = p / t, remaining_time = p % t;
    for (int i = 0; i < no_of_times; i++)
    {
        if (debug_exec_cronjob)
            printn_debug(cmd_str);
        interpret_command(cmd_str, 1); //force background procees
        sleep(t);
    }
    sleep(remaining_time);
    free(cmd_str);
}