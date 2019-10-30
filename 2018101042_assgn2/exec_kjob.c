/**
 * This function sends a signal to the process of the particular job
 **/

#include "shell.h"

int debug_exec_kjob = 0;

void exec_kjob(char *str, char **args)
{
	if (is_emptystr(args[1]))
	{
		print_err("Invalid usage: job number not found! \nUsage: kjob jobno signo");
		return;
	}
	if (is_emptystr(args[2]))
	{
		print_err("Invalid usage: signal number not found! \nUsage: kjob jobno signo");
		return;
	}
	if (!is_emptystr(args[3]))
	{
		print_err("Invalid usage: Too many arguments! \nUsage: kjob jobno signo");
		return;
	}
	char s;
	if (debug_exec_kjob)
	{
		s = getchar();
		printn_debug(args[1]);
		printn_debug(args[2]);
	}
	int pid, job_no, sig_no;
	job_no = atoi(args[1]);
	sig_no = atoi(args[2]);
	if (job_no <= 0)
	{
		print_err("Invalid usage: Invalid job number! \nUsage: kjob jobno signo");
		return;
	}
	if (sig_no < 0 || sig_no > 32)
	{
		print_err("Invalid usage: Invalid signal number! \nUsage: kjob jobno signo");
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
				if (debug_exec_kjob)
				{
					s = getchar();
					printn_debug("JOB FOUND");
					char *buffer = memalloc_str(MAX_LINE_LENGTH);
					sprintf(buffer, "JOBNO: %d  PID: %d SIGNAL: %d", c, all_jobs[i].pid, sig_no);
					print(buffer);
					free(buffer);
				}
				if (all_jobs[i].pid <= 0)
				{
					print_err("Error: Invalid pid");
					return;
				}
				kill(all_jobs[i].pid, sig_no);
				if (debug_exec_kjob)
				{
					s = getchar();
					printn_debug("JOB KILLED");
				}
				return;
			}
		}
		else
			all_jobs[i].pid = -1;
	}
	print_err("Error: job number does not exist");
	return;
}
