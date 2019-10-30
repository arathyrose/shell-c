/**
 * This function returns the status of the process using the pid given
 * Return Value Explanation:
 * *0 : INVALID or MISSING
 * *2 : BACKGROUND RUNNING PROCESS
 * *3 : STOPPED
 */

#include "shell.h"

int debug_get_status = 0;

int get_status(struct ongoing_processes P)
{
    char *path = memalloc_str(MAX_CURRENT_DIR);
    char *line;
    char s;
    sprintf(path, "/proc/%d/status", P.pid);
    FILE *file = fopen(path, "r");
    if (!file)
        return INVALID;
    size_t sz = 0;
    while (getline(&line, &sz, file) != -1)
    {
        if (strncmp("State", line, 5) == 0)
        {
            int cur = 0;
            if (debug_get_status)
            {
                s = getchar();
                print("LINE: ");
                printn_debug(line);
            }
            fclose(file);
            if (line[7] == 'S')
            {
                free(line);
                free(path);
                return BACKGROUND;
            }
            if (line[7] == 'R')
            {
                free(line);
                free(path);
                return BACKGROUND;
            }
            if (line[7] == 'T')
            {
                free(line);
                free(path);
                return STOPPED;
            }
            free(line);
            free(path);
            return BACKGROUND;
        }
    }
}
