#include "shell.h"
/**
 * STEPS
 * 1. find the number of cores in the laptop
 * 2. then somehow figure out how to find the number of interrupts(done)
 * 3. then wait for n seconds or exit on pressing d
 */
int debugg = 0;

void exec_nightswatch(char *arg, char **args)
{
    char buffer[MAX_BUFFER_LENGTH];
    char *line = (char *)malloc(sizeof(char) * MAX_LINE_LENGTH);
    if (!line)
        memory_error();
    if (!(args[1] != NULL && strcmp(args[1], "-n") == 0 && args[3] != NULL && ((strcmp(args[3], "interrupt") == 0 || strcmp(args[3], "dirty") == 0)) && (args[4] == NULL || args[4][0] == '\0')))
    {
        print_n("Usage: nightswatch -n (time in seconds) (interrupt | dirty) ");
        return;
    }
    int frequency = atoi(args[2]);
    if (frequency == 0)
    {
        print_n("Usage: nightswatch -n (time in seconds) (interrupt | dirty) ");
        return;
    }

    //find the number of cores
    size_t sz = 0;

    int no_of_cores = 0;
    FILE *core = fopen("/proc/cpuinfo", "r");
    if (core == NULL)
    {
        perror("cpuinfo: ");
        return;
    }
    while (getline(&line, &sz, core) != -1)
    {
        if (strncmp(line, "cpu cores", 9) == 0)
        {
            if (debugg)
                print_n(line);
            int cur = 0;
            for (int i = 11; line[i] != '\0'; i++, cur++)
                buffer[cur] = line[i];
            buffer[cur] = '\0';
            no_of_cores = atoi(buffer);
            break;
        }
    }
    fclose(core);

    // Timer function
    fd_set input_set;
    struct timeval timeout;
    FD_ZERO(&input_set);
    FD_SET(STDIN_FILENO, &input_set);

    if (strcmp(args[3], "interrupt") == 0)
    {
        print("0\tCPU0\tCPU1");
        int k = 1;
        while (1)
        {
            FILE *interrupt = fopen("/proc/interrupts", "r");
            ssize_t reads;
            size_t len = 0;
            char *line = NULL;

            if (interrupt == NULL)
            {
                perror("Error opening interrupt file: ");
                return;
            }
            long long int cpu[100] = {0};
            long long int read_cpu[100] = {0};
            getline(&line, &len, interrupt);
            while (getline(&line, &len, interrupt) != -1)
            {
                //check if the line ends with i8042
                char *p = line;
                while (*p == ' ' || *p == '\t')
                    p++;
                while (*p != ':')
                    p++; //Column 1 is not required

                for (int reading_cpu_no = 0; reading_cpu_no < no_of_cores; reading_cpu_no++)
                {
                    while (*p == ' ' || *p == '\t')
                        p++;
                    int cur = 0;
                    while (*p != ' ' && *p != '\t')
                        buffer[cur++] == *p++;
                    buffer[cur] = '\0';
                    read_cpu[reading_cpu_no] = atoi(buffer);
                }

                
            }

            sscanf(line, "%*lld: %lld %lld", &cpu[0], &cpu[1]);

            printf("%lld\t%lld\n", cpu[0], cpu[1]);
            k++;

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
            char *line = NULL;

            if (meminfo == NULL)
            {
                perror("Error opening meminfo file: ");
                return;
            }

            int i = 0;

            while (i < 17 && (reads = getline(&line, &len, meminfo)) != -1)
            {
                i++;
            }
            printf("%s", line);

            fclose(meminfo);

            timeout.tv_sec = frequency; // frequency seconds
            timeout.tv_usec = 0;        // 0 milliseconds
            select(1, &input_set, NULL, NULL, &timeout);
        }
    }
    free(line);
}
