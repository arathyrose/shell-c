/**
 * Implements nightswatch. 
 * TODO: quit on pressing q
 */

#include "shell.h"

void invalid_usage_nightswatch(char *s)
{
    print_err(s);
    print_err("Usage: nightswatch -n (time in seconds) (interrupt | dirty)");
    exit(0);
}

void exec_nightswatch(char *arg, char **args)
{
    char *buffer = memalloc_str(MAX_BUFFER_LENGTH);
    char *line = memalloc_str(MAX_LINE_LENGTH);
    if (is_emptystr(args[1]) || strcmp(args[1], "-n") != 0)
        invalid_usage_nightswatch("Invalid usage: Invalid format");
    if (is_emptystr(args[2]))
        invalid_usage_nightswatch("Invalid usage: time not found");
    if (is_emptystr(args[3]) || !(strcmp(args[3], "interrupt") == 0 || strcmp(args[3], "dirty") == 0))
        invalid_usage_nightswatch("Invalid usage: Invalid format");
    if (!is_emptystr(args[4]))
        invalid_usage_nightswatch("Invalid usage: Too many arguments");
    int frequency = atoi(args[2]);
    if (frequency == 0)
        invalid_usage_nightswatch("Invalid usage: Invalid time provided");

    // Timer function
    fd_set input_set;
    struct timeval timeout;
    FD_ZERO(&input_set);
    FD_SET(STDIN_FILENO, &input_set);

    if (strcmp(args[3], "interrupt") == 0)
    {
        print_n(":\tCPU0\tCPU1");
        while (1)
        {
            FILE *interrupt = fopen("/proc/interrupts", "r");
            ssize_t reads;
            size_t len = 0;
            if (interrupt == NULL)
            {
                perror("Error opening interrupt file: ");
                return;
            }
            getline(&line, &len, interrupt);
            getline(&line, &len, interrupt);
            getline(&line, &len, interrupt); //assuming that the third line contains what we want
            print(line);
            fclose(interrupt);
            timeout.tv_sec = frequency; // frequency seconds
            timeout.tv_usec = 0;        // 0 milliseconds
            select(1, &input_set, NULL, NULL, &timeout);
        }
    }
    if (strcmp(args[3], "dirty") == 0)
    {
        while (1)
        {
            FILE *meminfo = fopen("/proc/meminfo", "r");
            ssize_t reads;
            size_t len = 0;
            if (meminfo == NULL)
            {
                perror("Error opening meminfo file: ");
                return;
            }
            while (getline(&line, &len, meminfo) != -1)
            {
                if (strncmp(line, "Dirty", 5) == 0)
                {
                    print(line);
                    break;
                }
            }
            fclose(meminfo);
            timeout.tv_sec = frequency; // frequency seconds
            timeout.tv_usec = 0;        // 0 milliseconds
            select(1, &input_set, NULL, NULL, &timeout);
        }
    }
    free(line);
}
